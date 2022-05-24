//
// Created by Ao-jiayun on 2022/5/10.
//

#ifndef EX_CLASSINFORMATION_H
#define EX_CLASSINFORMATION_H
#include <fstream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define COURSE_MAX_NUMBER 20                                       //最大课程个数

#define MaxClass 100		//课程总数不超过100
#define MaxSemester 12		//学期总数不超过12

typedef   int  Elemtype;

//课程结构体
struct Course
{
    char id[10];            //课程编号
    char name[30];           //课程名称
  //  string name[20];
    int credit;                 //课程学分
    bool course_exist;             //判断当前课程是否存在
    int SemesterNum;		//学期数
    int MaxCredit;		//每学期学分上限
    int  ClassSum=0; //课程总数
    int Apcourse =0;  //先修课程数
};
//栈
typedef struct {
    Elemtype data[MaxClass];
    int top;
    int length;
}SqStack;

class Graph{
public:
    void Equality(Graph* p, int TopSort[]);
    void ToplSort(Graph* p,int TopSort[]); ////构造拓扑序列
    //void ToplSort(Graph* p); ////构造拓扑序列
    // void CreatTable(ALGraph* G,Graph* p);
    void ShortTime(Graph* p, int TopSort[]);
    void TwoTactics(Graph* p);      //两种编排策略
    bool ReadClassInformation( Graph* p);    //读取文件中的信息
    void KeyOutput(Graph* p);                    //从键盘输入课程信息
    void Modify_course(Graph* p);             //修改课程
    void Display_information(Graph* p);        //输出课程信息
    int Menu();


private:
         SqStack sqStack;
       // LinkNode linkNode;      ////链栈
        Course course[COURSE_MAX_NUMBER];       //最多不超过100    //课程信息
        int course_number;//课程数量
        int Adjmatrix[COURSE_MAX_NUMBER][COURSE_MAX_NUMBER];      //邻接矩阵存放课程之间的关系


};
#endif //EX_CLASSINFORMATION_H
