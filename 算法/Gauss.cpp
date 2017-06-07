/*
    高斯消元法（解整数解 & 化成上三角矩阵来求）
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

#define maxn 1010 

int f_c_cnt,b_l_cnt;
int rec_x[maxn];                //记录 x的值的数组 
int matrix[maxn][maxn];            //记录系数的矩阵 

bool free_x[maxn];                //判断是否为自由元 

void prework(){
    freopen("x.in", "r", stdin);
    scanf("%d%d",&f_c_cnt,&b_l_cnt);        //方程数 & 变量数 
    for(int i=1;i<=f_c_cnt;i++)
        for(int j=1;j<=b_l_cnt+1;j++)
            scanf("%d",&matrix[i][j]);
}

int gcd(int a,int b){
    int t;
    while(b) t=b,b=a%b,a=t;
    return a;
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

void swap(int i,int j){
    int t;
    for(int k=i;k<=b_l_cnt+1;k++)
        t=matrix[i][k],matrix[i][k]=matrix[j][k],matrix[j][k]=t;
}

int gauss(){
    
    for(int i=1;i<=b_l_cnt;i++)
        rec_x[i]=0,free_x[i]=true;
    
    int line_0,now_b_l,max_l;                                //line_0 表示这条线以下的全是 0，刚开始会从 1开始向下扫描 
    
    for(line_0=now_b_l=1;line_0<=f_c_cnt && now_b_l<=b_l_cnt;line_0++,now_b_l++){
        max_l=line_0;                                         //在当前变量 now_b_l中系数绝对值最大的 
        for(int fuc=line_0+1;fuc<=f_c_cnt;fuc++)             //找到变量系数最大的这行 
            if(abs(matrix[max_l][now_b_l])<abs(matrix[fuc][now_b_l]))
                max_l=fuc;
        
        if(max_l!=line_0)    swap(line_0,max_l);                  //将绝对值最大的替换当前行，可以防止此行为 0，如果实数运算可以减小误差 
        if(!matrix[line_0][now_b_l]) {line_0--;continue;}     //如果这行绝对值最大的也是0，说明这个变量没有系数了，将这个变量过滤 
        
        for(int fuc=line_0+1;fuc<=f_c_cnt;fuc++)
            if(matrix[fuc][now_b_l]){
                int LCM=lcm(abs(matrix[fuc][now_b_l]),abs(matrix[line_0][now_b_l]));    //加减消元的时候，用他们的LCM来消元 
                int mul=LCM/matrix[fuc][now_b_l];                //这一行应该乘多少 
                int div=LCM/matrix[line_0][now_b_l];            //要消元的行要乘多少 
                if((long long) matrix[fuc][now_b_l]*matrix[line_0][now_b_l]<0)    div=-div;    //因为之前一直讨论的是绝对值，这里要判断负数 
                
                for(int b_l=now_b_l;b_l<=b_l_cnt+1;b_l++)
                    matrix[fuc][b_l]=matrix[fuc][b_l]*mul-matrix[line_0][b_l]*div;    //加减消元 
            }
    }
    
            
    for(int fuc=line_0;fuc<=f_c_cnt;fuc++)        //如果所有点都有解，line_0返回值应该是 f_c_cnt+1，如果line_0以下系数就都是 0了 
        if(matrix[fuc][b_l_cnt+1])                //如果系数是0而常数项不是0，那么就是无解 
            return -1;
        
    if(line_0<f_c_cnt+1){                        //如果不是所有点都能解出来，那么多解的情况便是出现了变元 
        for(int fuc=line_0-1;fuc>=1;fuc--){        //在line_0以上的是系数不为 0的方程，考虑才有意义 
            int uns_sum=0,uns_num;                //uns_sum 表示 unsure的变量的数量，uns_num表示哪个unsure的是哪个（些）变量 
            for(int b_l=1;b_l<=b_l_cnt;b_l++)
                if(matrix[fuc][b_l] && free_x[b_l])
                    uns_sum++,uns_num=b_l;         
            
            if(uns_sum>1)    continue;            //如果一个方程中有超过一个不知道解的变量，那就解不出了
            
            int ans_c=matrix[fuc][b_l_cnt+1];    //否则可以把这个不确定的量解出来，将常数项定为 ans_c 
            for(int b_l=1;b_l<=b_l_cnt;b_l++)
                if(matrix[fuc][b_l] && b_l!=uns_num)     //减去其中已知的变量*它们的系数 
                    ans_c-=matrix[fuc][b_l]*rec_x[b_l];
            
            rec_x[uns_num]=ans_c/matrix[fuc][uns_num];     //最后的解就是常数项除以要求的变量的系数 
            free_x[uns_num]=false;
        }
        
        return b_l_cnt-line_0+1;                //返回变元的个数 
    }
        
    for(int fuc=f_c_cnt;fuc>=1;fuc--){            //除了无解和无数解，那就是唯一解了 
        int ans_c=matrix[fuc][b_l_cnt+1];        //同上，将解从最后一个变量开始向上代入消元 
        for (int b_l=fuc+1;b_l<=b_l_cnt;b_l++)
                ans_c-=matrix[fuc][b_l]*rec_x[b_l];
        rec_x[fuc]=ans_c/matrix[fuc][fuc];
    }
    return 0;
}

void mainwork(){
    int flag=gauss();
    if(flag==0){
        for(int i=1;i<=b_l_cnt;i++)
            printf("x%d=%d\n",i,rec_x[i]);
    }
    else if(flag>0){
        printf("It has %d free x\n",flag);
        for(int i=1;i<=b_l_cnt;i++)                //输出已知的解 & 还不知道的解 
            if(free_x[i])
                printf("x%d is unsure!\n",i);
            else
                printf("x%d=%d\n",i,rec_x[i]);
    }
    else
        printf("NO ANSWER");
}

int main(){
    prework();
    mainwork();
    return 0;
}