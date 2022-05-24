#include <iostream>
#include "ClassInformation.h"
#define  CLASSNUMBER 14     //课程数

int main() {

    Graph graph, *p; //重新创建图
    p = (Graph*)malloc(sizeof(Graph));  //分配空间
    int TopSort [CLASSNUMBER];
//    graph.ReadClassInformation(p);
    memset(TopSort, 0, sizeof(TopSort));    //将TopSort中的初始化为0
    selct:
    switch(graph.Menu()){
        case 1:  //1.文件形式读入课程信息
        {
            system("cls");        //清空屏幕
            graph.ReadClassInformation(p);
            system("pause");
            system("cls");        //清空屏幕
            goto selct;
        }
        case 2:  //2.从键盘获取
        {
            system("cls");        //清空屏幕
            graph.KeyOutput(p);
            system("pause");
            goto selct;
        }
        case 3:  //修改
        {

            system("cls");
            graph.Modify_course(p);   //修改课程信息
            system("pause");
            goto selct;
    }
        case 4:  //打印
        {
            system("cls");
            graph.Display_information(p);                        //输出课程信息
            system("pause");
            goto selct;
        }
        case 5:
        {
            system("cls"); //均衡学习
            graph.ToplSort(p,TopSort);                        //输出课程信息
            graph.Equality( p,  TopSort);
           // graph.ToplSort(p);
            system("pause");
            goto selct;
        }
        case 6:  //  集中
        {
            system("cls");
            graph.ToplSort(p,TopSort);                        //输出课程信息
            graph.ShortTime( p,TopSort);
            system("pause");
            goto selct;
        }
    }
    cout << "期待您再次使用！";
    return 0;
}


