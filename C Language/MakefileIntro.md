# Makefile 教程

## makefile 产生原因

- 代码变成可执行文件，叫做编译；
- 先编译这个，还是先编译哪个（编译的安排），叫做构建。

## makefile 简单实例

例如有三个文件：main.c hello.c hello.h

makefile 将这样构建：
```
<--tab-->helloMain: main.c hello.c hello.h
    gcc -o helloMain main.c hello.c hello.h

    clean:
        rm -rf helloMain
```

## makefile 规则

    <target>(目标): <prerequisites>(前置条件)
    [tab] <commands>(命令)

## gcc 编译过程

一步到位：gcc test.c -o test.exe
分解：
- gcc -E test.c -o test.i   预处理
- gcc -S test.i -o test.s   编译
- gcc -c test.s -o test.o   汇编
- gcc test.o -o test.exe    链接

## Makefile 标准实例

还是用上面哪个例子：

makefile:
    cc = gcc
    prom = helloMain
    deps = hello.h
    obj = main.o hello.o

    $(prom): $(obj)
        $(cc) -o $(prom) $(obj)
    main.o: main.c $(deps)
        $(cc) -c main.c
    hello.o: hello.c $(deps)
        $(cc) -c hello.c

    clean: 
        rm -rf helloMain hello.o main.o

## Makefile 高级

适用于更大型项目的构建，待...