//
// Created by Ao-jiayun on 2022/5/10.
//

#include <stack>
#include "ClassInformation.h"


bool Graph::ReadClassInformation( Graph *p) {
   // int choose=0;
    //ifstream file2("c://pdos.def");       //以输入方式打开文件
    //ofstream file3("c://x.123");          //以输出方式打开文件
    // file1.close();就把file1相连的文件关闭

    std::ifstream in("E:\\S-ata-strcture\\Ex\\cmake-build-debug\\new 2.txt");
    if (!in.is_open()) {     //!is_open() 判断文件是否存在
        cout << "文件不存在！" <<endl;
        cout << "请在文件中建立" << endl;
        in.close();
        return false;
    }
    //在文件中获取后存入数组，对应课程编号、课程名、学分
    in >> p->course_number;   //逐字输出

    cout<<"导入信息如下"<<endl;
    // system("cls");      //输出刚输入的数
    for (int i = 1;i <= p->course_number;i++)
    {

        in >> p->course[i].id;
        in>> p->course[i].name ;
        in>>p->course[i].credit;
        cout<<"第"<<i<<"门课程编号是："<<p->course[i].id<<endl;
        cout<<"课程名是："<<p->course[i].name<<endl;
        cout<<"学分是："<<p->course[i].credit<<endl;
        p->course[i].course_exist = true;
    }
    //输出课程信息
    int i, j;
    for (int k = 0;k < p->course_number;k++)   //将文件的信息存入    Adjmatrix 中
    {
        in >> i >> j;
        p->Adjmatrix[i][j] = 1;                   //表示课程ci是课程cj的先修课程

        }
//    for (int i = 1;i <= p->course_number;i++)
//    {
//        for (int j = 1;j <= p->course_number;j++)
//            cout <<std::setw(4)<< p->Adjmatrix[i][j] << " ";  //邻接矩阵
//        cout << endl;
//    }
    in.close();
    cout << "文件里面的课程信息已成功录入！" << endl;
    }



//键盘形式输入课程信息创建图
//输入参数  1、学期总数 2、一学期的学分上限 3、课程编号 4、学分 5、直接先修课程编号
void Graph::KeyOutput(Graph* p){
     //ALGraph *G;
   // p->ALGRAPHS.ExtraInfo = (Message*)malloc(sizeof(Message));		//初始化指针
    system("cls");        //清空屏幕
    // cout << " 学期总数(有几个学期)  每学期学分上限  一学期课程总数（每学期*课程）" << endl<<endl;
   //  scanf("%d%d%d",&p->course->SemesterNum,&p->course->MaxCredit,&p->course->ClassSum);
        cout<<" 学期总数(有几个学期)"<<endl;
        cin>>p->course->SemesterNum;
         cout<<" 每学期学分上限"<<endl;
         cin>>p->course->MaxCredit;
         cout<<" 一学期课程总数（总数为：每学期*课程）"<<endl;
         cin>>p->course->ClassSum;
    if (p->course->ClassSum > MaxClass) {                          // //MaxClass为学期总数
        printf("超出最大课程总数%d,请更改数据\n", MaxClass);
        exit(1);
    }
    if (p->course->SemesterNum > MaxSemester) {  //SemesterNum 学期数
        printf("超出最大学期数%d,请更改数据\n", MaxSemester);
        exit(1);   //退出 如return -- exit
    }
  //  cout << "请输入课程总数" << endl;
  //  cin >> p->course_number;  //从键盘输入
//    system("cls");        //清空屏幕
//    system("pause");
    cout << "您输入课程总数是"<<(p->course->SemesterNum * p->course->ClassSum) << endl;
//    printf("若您不先修可直接输入 <0>"); cout<<endl;
    printf("若不输入课程，则请输入 <0>"); cout<<endl;  //键盘获取先修课信息
    printf("您要学习的课程数为:");
    cin >> p->course_number;  //获取先修的课程数目
    p->course->Apcourse=p->course_number;  //存入结构体中
    if(p->course_number==0) {
        printf("您没有输入课程信息");
       // printf("将重新从文件导入课程信息");
       // ReadClassInformation( p); //重新导入信息
        return;
    }
    int tag=0;
    cout << "请依次输入课程编号、课程名称和学分" << endl;
    system("pause");    //请按任意键继续. . .
    for (int i = 1;i <= p->course_number;i++)
        {
            cout << "第" << i << "门的";
            cout << "课程编号是：";
            cin >> p->course[i].id;
            cout << "课程名称是：";
            cin >> p->course[i].name;
            cout << "课程分数是：";
            cin >> p->course[i].credit;  // 课程编号、课程名称和学分
          //  grade += p->course[i].credit;

            p->course[i].course_exist = true;
            }
    printf("输入先修课的值是：%d",p->course_number);
    cout<<endl;
    memset(p->Adjmatrix, 0, sizeof(p->Adjmatrix));    //初始化adjmatrix全部元素为0
    cout << "请输入课程之间的前后关系:请输入数字(由课程编号确定 每次输入一个数)" << endl;
    printf("例如 1  2 课程1是2的必修课");cout<<endl;
    cout<<endl;
        ////根据课程建立邻接表结点 文件还未关闭，依次遍历表中俩两一组的数字
      int i, j, k;
    for (k = 1; k<=p->course_number/2;k++)
    {
        cin >> i >> j;
        p->Adjmatrix[i][j] = 1;   //表示课程ci是课程cj的先修课程
    }
    cout << "键盘输入的课程信息已成功录入！" << endl;
}


////利用结构体建立邻接矩阵
//void Graph::CreatTable(ALGraph* G ,Graph* p ){
//
//    G->VexNum=p->course->ClassSum;  //获取修改的最大课程数
//    FILE* fp = fopen("E:\\S-ata-strcture\\Ex\\cmake-build-debug\\new 2.txt", "r");
//    if (NULL == fp) {
//        printf("文件路径有误！！！");
//        exit(1);
//    }
//    G->Vertics = (VexNode*)malloc(sizeof(VexNode) * G->VexNum);
//    for (int i = 0; i < G->VexNum; i++)
//        G->Vertics[i].FirstEdge = NULL;		//初始化
//    for (int i = 0; i < G->VexNum; i++) {		//读取课程信息
//        fscanf(fp, "%s%d", G->Vertics[i].Date, &G->Vertics[i].Credit);		//读取课程名称和学分
//        while ('\n' != fgetc(fp)) {		//根据先修课程建立邻接表结点
//            char str[4];
//            int s;
//            fscanf(fp, "%s", str);
//            s = Locate(str);
//            if (s < 0 || s > G->VexNum) {		//判断课程是否有错误
//                printf("%s输入错误！\n", G->Vertics[i].Date);
//                exit(1);
//            }
//            EdgeNode* p = (EdgeNode*)malloc(sizeof(EdgeNode));		//更新邻接表结点
//            p->AdjVex = i;
//            p->Next = G->Vertics[s].FirstEdge;
//            G->Vertics[s].FirstEdge = p;
//            G->ArcNum++;
//        }
//    }
//    fclose(fp);
//    for (int i = 0; i < G->VexNum; i++)		//更新入度
//        G->Vertics[i].InDegree=0;
//    for (int i = 0; i < G->VexNum; i++) {
//        for (EdgeNode* p = G->Vertics[i].FirstEdge; NULL != p; p = p->Next) {
//            G->Vertics[p->AdjVex].InDegree++;
//        }
//
//    }
//}

//输出课程信息
void Graph::Display_information(Graph* p) {
    int Choice = 0;
    printf("请输入您要输出的信息： 1（课程信息）  2、（课程的先后顺序）");
    cout << endl;
    cin >> Choice;
    if (p->course->Apcourse== 0&& p->course_number==0 ) {
        printf("没有获取到课程信息");
        cout << endl;
        return;
    }
    if (Choice == 1) {

        cout << "课程信息如下：" << endl;
        cout << "课程编号 " << "课程名称 " << "         课程学分   " << endl;
        for (int i = 1; i <= p->course_number; i++) {
            cout << std::setw(5) << p->course[i].id << "  \5";
            cout << p->course[i].name << " ";
            cout << p->course[i].credit << std::setw(5) << " ";
            cout << endl;
        }
    }
    if (Choice == 2) {
        cout << endl << "课程关系矩阵：(最多为对应1-" << p->course_number<< "号课程,课程从 1 开始)" << endl;
        for (int i = 0; i <= p->course_number; i++) {
            if (i >= 10)
                cout << i << std::setw(6);
            else cout << i << std::setw(4);
        }
        cout << endl;//输出1-14
        for (int i = 0; i <= 14; i++) {
            cout << "----" << std::setw(4);//-------------
        }
        cout << endl;
        for (int i = 1; i <= p->course_number; i++) {
            for (int j = 1; j <= p->course_number; j++)
                cout << std::setw(4) << p->Adjmatrix[i][j] << " ";  //邻接矩阵
            cout << endl;
        }
    }
    if(Choice!=1&&Choice!=2)
    {
        printf("您输入的内容有误");
        cout<<endl;
            return;
}
}
//修改课程信息
void Graph::Modify_course(Graph* p)
{
    //修改之前需先判断该课程编号是否在文件中
    int number=0,choice;
    string input ,Str;
    int temp=0;
    bool Ex= true;
    int tag=0;
    do{
        cout << "请输入您想修改的课程编号：" << endl;
        cin >> input;
        cout<<endl;
        while(!tag){
            for (int i = 1; i <= p->course_number; i++){
                Str = p->course[i].id;
                temp++;
                    //int strcmp(const char *input, const char *Str); //strcmp 判断是否相等 相等 为 0
            if(input==p->course[i].id){
                  printf("您要修改的课程存在");
                number= temp;
                  tag=1;
                                }
                }
              if(tag==0)
              { printf("该课程不存在");
                  return;
              }
        }
        cout<<endl;
     //   printf("课程位置下标：%d",number); cout<<endl;

      //  cout<<number<<endl;
        cout << "您想修改的信息为(1.课程名称 2.课程学分)：" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "请输入新的课程名称" << endl;
            cin >> p->course[number].name;
        }
        if (choice == 2)
        {
            cout << "请输入新的课程学分" << endl;
            cin >> p->course[number].credit;
        }
        cout << "修改成功" << endl;
        Ex= false;



//    for (int i = 1; i <= p->course_number; i++) {
//            Str = p->course[i].id;
//            int strcmp(const char *input, const char *Str);
//            //if ((input.compare(p->course[i].id))){  //相同为0
//            cout << strcmp << endl;
////           if(strcmp==0){
//
//            if(input==p->course[i].id){
////            cout<<"输出课程编号"<<p->course[i].id<<endl;
//                printf("您要修改的课程存在");
//            cout<<endl;
            // 去掉C 保留数字
//                for (int q = 1; q < input.length(); q++)    //标号是c开头
//                {
//                    if (input[q] >= '0'&&input[q] <= '9')
//                    {
//                        temp += input[q];
//                    }
//                }
//                number= temp;
//                cout<<number<<endl;
//                cout << "您想修改的信息为(1.课程名称 2.课程学分)：" << endl;
//                cin >> choice;
//                if (choice == 1)
//                {
//                    cout << "请输入新的课程名称" << endl;
//                    cin >> p->course[number].name;
//                }
//                if (choice == 2)
//                {
//                    cout << "请输入新的课程学分" << endl;
//                    cin >> p->course[number].credit;
//                }
//                cout << "修改成功" << endl;
//                Ex= true;
//            }
//            printf("请重新输入");


    }while (Ex);

}
void InitStack(SqStack &s){
    s.top=-1;
    printf("初始化完成SqStack ");    cout<<endl;
}
//进栈
bool StakEmpty(SqStack &s,Elemtype x){
//    InitStack(s);
//    s.top=-1;
    if(s.top==MaxClass-1)return false;
    printf("进栈头是：%d",s.top);    cout<<endl;
    cout<<endl;
    s.top+=1;
    s.data[s.top]=x;
//    printf("进栈");
//    cout<<"--值是"<<x<<endl;
    s.length++;
    return true;
}
//出栈
bool Pop(SqStack &s,Elemtype *x){
    if(s.top==-1)return false;
//    printf("出栈头是：%d",s.top);   cout<<endl;
    *x=s.data[s.top--];
 //   printf("出栈值是%d ",x);    cout<<endl;
    return true;
}
//读值
bool GetTop(SqStack &s){
    if(s.top==-1)return false;
    printf("读取值时栈头是：%d",s.top);     cout<<endl;
    s.data[s.top];
    cout<<"读取值 是"<< s.data[s.top]<<endl;
    s.top--;
    return true;
}
//构造拓扑序列

//void Graph::ToplSort(Graph* p,int TopSort[]) {
//
//   SqStack *S;
//    S= (SqStack*)malloc(sizeof(SqStack));  //分配空间
//    InitStack(*S);
//    cout<<endl;
//    cout<<"获取头指针"<<S->top<<endl;
//    int indegree[p->course_number + 1];               //存放各结点的入度（从indegree[1]开始存放）
//    memset(indegree, 0, sizeof(indegree));          //将indegree全部赋值为0
// //   for(int i=0;i<p->course_number;i++)cout<<indegree[i]<<"--"<<endl;         //   全0
//    for (int i = 1;i <= p->course_number;i++)     //统计各结点的入度
//        for (int j = 1;j <= p->course_number;j++)
//            if (p->Adjmatrix[i][j]) indegree[j]++;
//   // for(int i=0;i<p->course_number;i++)cout<<indegree[i]<<"-***-"<<endl;         //   全0
//    for (int i = 1; i <= p->course_number; i++)   //入度为0，则压入栈
//    {
//        if (!indegree[i]) {     // 1、8、9
//            // printf("在拓扑中进栈"); //把i值进栈
//            StakEmpty(*S, i);        //入栈
//         //   cout << "StakEmpty 一次入栈  --" << i << endl;
//
//        }
//    }
//    cout<<"二次获取头指针"<<S->top<<endl;   // 2
//    int touz=S->top;
//    int num=0, t;
//    while(S->top!=0){  // 非空
//        printf("进入判断");
//        int TopEle;
//      //  for(int i=S->length;i>=0;i--)  //length=2
//        Pop(*S,&t); //获取栈顶元素 出栈
//        TopEle=t; cout<<endl;   //获取栈中的值 9 8 1
//        printf("TopEle的值是：%d",TopEle);   cout<<endl;
//        TopSort[num]=TopEle;  //将元素 (9 8 1)存入TS数组
//       printf("TopSort的值%d",TopSort[num]);
//        num++;
//        for(int j=0;j<p->course_number;j++){
//            if(p->Adjmatrix[TopEle++][0]){
//                if(!--indegree[0])
//                    StakEmpty(*S,j);
//                cout << "StakEmpty 二次入栈  --" << j << endl;  //12 13
//
//            }
//        }
//    }
//
//    }

//构造拓扑序列

void Graph::ToplSort(Graph* p, int TopSort[])
{
    int indegree[p->course_number + 1];           //存放各结点的入度（从indegree[1]开始存放）
    memset(indegree, 0, sizeof(indegree));
    for (int i = 1;i <= p->course_number;i++)     //统计各结点的入度
        for (int j = 1;j <= p->course_number;j++)
            if (p->Adjmatrix[i][j]) indegree[j]++;

    stack <int> s;  //创建栈
    for (int i = 1;i <= p->course_number;i++)     //入度为0，则压入栈
        if (!indegree[i]) s.push(i);                //push() 在栈顶增加元素

    int num = 0;                                  //开始进行拓扑排序
    while (!s.empty())            //栈非空 作为判断容器是否为空的函数；
    {
        int top;
        top = s.top();                            //取栈顶元素
        s.pop();                                  //出栈
        TopSort[num++] = top;       //保存栈顶元素
        for (int j = 1;j <= p->course_number;j++)
        {
            if (p->Adjmatrix[top][j])
            {
                if (!--indegree[j]) s.push(j);    //每出一个元素，则它指向的结点入度减1
            }                                     //并判断是否为0，若为零则入栈
        }
    }
}

//按各学期中的学习负担尽量均匀地制定教学计划
void Graph::Equality(Graph* p, int TopSort[])
{
    //存入文件中
    ofstream out("Equality-class.txt");
    int average_credit = 0;
    int semester=0;  //学期数
    for (int i = 1;i <= p->course_number;i++)     //计算课程总学分
    {
        average_credit += p->course[i].credit;
    }
    printf("总分是:%d",average_credit); cout<<endl;
    int remaine_credit = average_credit;          //remaining_credit为剩余总学分
    semester=p->course->SemesterNum;                //获取聪从键盘获取的学期数目
    if(semester==NULL){
        printf("您没有输入学期数目，将按默认值8分配");    //4年制
        cout<<endl;
        average_credit /= 8;     //假设共8个学期
    }
    else   average_credit /=semester;
    out << "平均学分为:" << average_credit << endl << endl;
    int term_number = 1, j = 0;                   //学期编号、拓扑序列的下标
   // printf("剩余总分是%d",remaine_credit);  cout<<endl;
    while (remaine_credit > 0)                    //总学分还剩余
    {
        int term_credit = 0;
        int term_remaine_credit = average_credit; //当前学期还能修的学分  -- 获取每学期的平均学分
        out << "第" << term_number << "学期:" << endl;
        if (remaine_credit > term_remaine_credit) //剩余总学分多于当前学期还能修的学分
        {
            while (term_remaine_credit > 0)       //当前学期还能修的学分还剩余
            {
                out << p->course[TopSort[j]].id << " ";     //j 为0 则为入栈为0的节点
                out << p->course[TopSort[j]].name << " ";
                out << p->course[TopSort[j]].credit << " ";

                term_remaine_credit -= p->course[TopSort[j]].credit;
                remaine_credit -= p->course[TopSort[j]].credit;
                term_credit += p->course[TopSort[j]].credit;
                j++;
                out << endl;
            }
            term_number++; //当前学期没有还能修的学分，换下学期
        }
        else  //剩余总学分少于或等于当前学期还能修的学分
        {
            out << p->course[TopSort[j]].id << " ";
            out << p->course[TopSort[j]].name << " ";
            out << p->course[TopSort[j]].credit << " ";

            term_remaine_credit -= p->course[TopSort[j]].credit;  //当前学期学分减去当前学科的学分
            remaine_credit -= p->course[TopSort[j]].credit;   //总学分减去当前学科的学分
            term_credit += p->course[TopSort[j]].credit;  //当前学期的分数
            j++;
            out << endl;
        }
        out << "本学期总学分为：" << term_credit << endl << endl;
    }
    out << "学期总数为:" << term_number << endl;
    out.close();
    cout << "教学计划已保存到文件Equality-class.txt 中" << endl;
}

// 可能短的时间完成学习制定教学计划
void Graph::ShortTime(Graph* p, int TopSort[]) {
    ofstream out("FinishTheProjectShort.txt");
    int term_credit;                              //学期总学分
    int term_number = 1;                          //学期编号
    int number = 0;                               //拓扑排序结果下标
    int remain_credit = 0;                        //剩余总学分
    int EachCredit = 0;
    for (int i = 1; i <= p->course_number; i++)     //计算课程总学分
    {
        remain_credit += p->course[i].credit;
    }

    EachCredit = p->course->MaxCredit;  //获取键盘设置的每学期学分上限
    // cout<<"没有输入学期数EachCredit的值是："<<EachCredit<<endl;  // 没有进行课程的输入则为0
   // printf("总分是：%d",remain_credit);
    if (EachCredit == 0) {
        printf("没有设置每学期的学分，默认设置为12");
        while (remain_credit > 12)   //每学期学分上限为12
        {
            term_credit = 0;
            out << "第" << term_number << "学期:" << endl;
            while (term_credit + p->course[TopSort[number]].credit < 12) {    //当前本学期总学分+下一个要安排课程的学分<学分上限12
                out << p->course[TopSort[number]].id << " ";
                out << p->course[TopSort[number]].name << " ";
                out << p->course[TopSort[number]].credit << " " << endl;
                term_credit += p->course[TopSort[number]].credit;
                remain_credit -= p->course[TopSort[number]].credit;
                number++;
            }
            term_number++;
            out << "本学期总学分为：" << term_credit << endl << endl;

            term_credit = 0;
            out << "第" << term_number << "学期:" << endl;//总学分剩余小于12时
            while (remain_credit > 0) {
                out << p->course[TopSort[number]].id << " ";
                out << p->course[TopSort[number]].name << " ";
                out << p->course[TopSort[number]].credit << " " << endl;
                term_credit += p->course[TopSort[number]].credit;
                remain_credit -= p->course[TopSort[number]].credit;
                number++;
            }
            out << "本学期总学分为：" << term_credit << endl << endl;
            out << "学期总数为:" << term_number << endl;
            out.close();
            cout<<endl;
            cout << "教学计划已保存到文件--Finish the project short.txt中" << endl;
        }
    }
    else {
        while (remain_credit > EachCredit)   //每学期学分上限为12
        {
            term_credit = 0;
            out << "第" << term_number << "学期:" << endl;
            while (term_credit + p->course[TopSort[number]].credit < 12)
            {    //当前本学期总学分+下一个要安排课程的学分<学分上限12
                out << p->course[TopSort[number]].id << " ";
                out << p->course[TopSort[number]].name << " ";
                out << p->course[TopSort[number]].credit << " " << endl;
                term_credit += p->course[TopSort[number]].credit;
                remain_credit -= p->course[TopSort[number]].credit;
                number++;
            }
            term_number++;
            out << "本学期总学分为：" << term_credit << endl << endl;
        }
        term_credit = 0;
        out << "第" << term_number << "学期:" << endl;//总学分剩余小于12时
        while (remain_credit > 0)
        {
            out << p->course[TopSort[number]].id << " ";
            out << p->course[TopSort[number]].name << " ";
            out << p->course[TopSort[number]].credit << " " << endl;
            term_credit += p->course[TopSort[number]].credit;
            remain_credit -= p->course[TopSort[number]].credit;
            number++;
        }
        out << "本学期总学分为：" << term_credit << endl << endl;
        out << "学期总数为:" << term_number << endl;
        out.close();
        cout << "教学计划已保存到文件--Finish the project short.txt中" << endl;
    }
}
//程序菜单
int Graph::Menu()
{
    int i;
    do {
        system("cls");
        cout << "***************教学计划编制系统****************" << endl << endl;
        cout << "           1.文件形式读入课程信息" << endl;
        cout << "           2.键盘形式读入课程信息" << endl;
        cout << "           3.课程信息修改" << endl;
        cout << "           4.课程信息输出" << endl;
        cout << "           5.按各学期中的学习负担尽量均匀地制定教学计划" << endl;
        cout << "           6.按尽可能短的时间完成学习制定教学计划" << endl;
        cout << "           7.退出程序" << endl << endl;
        cout << "********************************************" << endl << endl;
        cout << "           请输入您的选择：";
        cin >> i;

    } while (i < 1 || i>7);
    return i;
}
