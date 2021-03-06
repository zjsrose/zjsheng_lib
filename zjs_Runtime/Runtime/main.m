//
//  main.m
//  Runtime
//
//  Created by autel on 17/6/3.
//  Copyright © 2017年 zhongjiasheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StudentModel.h"
#import <objc/runtime.h>
#import <objc/message.h>

void exchangeMethod();
void addNewMethod();
void changeVariable();


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...

        exchangeMethod();
        addNewMethod();
        changeVariable();
        
        StudentModel *student = [StudentModel modelWithDic:@{@"age":@"18",@"name":@"zjsheng",@"height":@"188"}];
        NSLog(@"age:%@,name:%@",student.age,student.name);
        
        

    }
    return 0;
}


void createAInstance(){
    
    
    
    Class People = objc_allocateClassPair([NSObject class], "People", 0);
    
    objc_registerClassPair(People);
    
    SEL sel = sel_registerName("test");
    IMP imp = imp_implementationWithBlock(^(id this, id args, ...){
        
        NSLog(@"方法的调用者为 %@",this);
        return @"返回值测试";
    });
    
    class_addMethod(People, sel, imp, "@@:@");
    
    class_replaceMethod(People, @selector(description), imp_implementationWithBlock(^(id this,...){
        return @"我是Person类的对象";
    }), "@@:");
    
    
}


//4. 动态交换方法实现
void exchangeMethod(){
    
    StudentModel *student = [StudentModel new];
    student.name = @"乔布斯";
    [student eat];
    [student sleep];
    
    Method methodEat = class_getInstanceMethod([student class], @selector(eat));
    Method methodSleep = class_getInstanceMethod([student class], @selector(sleep));
    
    method_exchangeImplementations(methodEat, methodSleep);
    
    [student eat];
    [student sleep];
}


//3. 动态为Category扩展加属性    objc_getAssociatedObject   objc_setAssociatedObject
//2.动态添加方法     class_addMethod

void happyNewYear(id self, SEL _cmd){
    
    NSLog(@"新年快乐");
}

void addNewMethod(){
    
    StudentModel *student = [StudentModel new];
    student.name = @"乔布斯";
    
    class_addMethod([student class], @selector(join), (IMP)happyNewYear, "v@:");
    [student performSelector:@selector(join)];
}


//1. 动态变量控制  '乔布斯'->'jobs'
void changeVariable() {
    
    StudentModel *student = [[StudentModel alloc] init];
    student.name = @"乔布斯";
    NSLog(@"%@",student.name);
    
    unsigned outCount = 0;

//    Ivar *ivares = class_copyIvarList([student class], &outCount);
//    for (int i = 0; i < outCount; i ++) {
//
//        Ivar var = ivares[i];
//        const char *varName = ivar_getName(var);
//        NSString *name = [NSString stringWithCString:varName encoding:NSUTF8StringEncoding];
//
//        if ([name isEqualToString:@"_name"]) {
//
//            object_setIvar(student, var, @"jobs");
//
//            break;
//        }
//
//    }
    

    Ivar ivar = class_getInstanceVariable([student class], "_name");
    object_setIvar(student, ivar, @"jobs");
    
    
    NSLog(@"%@",student.name);
    
    
    
    
    Method *methodes = class_copyMethodList(object_getClass(student), &outCount);
    for (int i = 0; i < outCount; i++) {
        
        Method method = methodes[i];
        
        SEL methodSel = method_getName(method);
        const char *methodName = sel_getName(methodSel);
        const char *encoding = method_getTypeEncoding(method);
        
        printf("methodName:%s,encoding:%s\n",methodName,encoding);
    }
    
    
    
    
    
}

//object_
//class_
//method_
//ivar_
//property_
//objc_
//protocol_
//sel_
//imp_


struct objc_objectx {
    Class _Nonnull isa;
};

struct objc_classx {
    Class _Nonnull isa;
    Class _Nullable super_class;
    const char * _Nonnull name;
    long version;
    long info;
    long instance_size;
    struct objc_ivar_list * _Nullable ivars;
    struct objc_method_list * _Nullable * _Nullable methodLists;
    struct objc_cache * _Nonnull cache;
    struct objc_protocol_list * _Nullable protocols;
};

struct objc_methodx {
    SEL _Nonnull method_name                                ;
    char * _Nullable method_types                           ;
    IMP _Nonnull method_imp                                 ;
};

struct objc_ivar {
    char * _Nullable ivar_name                               ;
    char * _Nullable ivar_type                               ;
    int ivar_offset                                          ;
    int space                                                ;
};

struct objc_category {
    char * _Nonnull category_name                            ;
    char * _Nonnull class_name                               ;
    struct objc_method_list * _Nullable instance_methods     ;
    struct objc_method_list * _Nullable class_methods        ;
    struct objc_protocol_list * _Nullable protocols          ;
}                                                            ;
