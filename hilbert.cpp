#include<cstdio>
int n=6;//阶数
int d=1;//这个值表示方向，可以取到0,1,2,3，分别代表右下左上。这里初始设为1
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//这个二维数组代表不同向不同方向移动时x和y坐标要如何变化
int pow(int a,int b){//阶乘
	int x=1;
	while(b--)x*=a;
	return x;
}
void hilbert(int l/*阶数*/,bool b/*是否反向旋转*/){
	if(!l){return;}
	l--;
	if(b)d=(d+1)%4;else d=(d+3)%4;
	hilbert(l,!b);
	printf(" l%d,%d",dir[d][0],dir[d][1]);
	if(b)d=(d+3)%4; else d=(d+1)%4;
	hilbert(l,b);
	printf(" l%d,%d",dir[d][0],dir[d][1]);
	hilbert(l,b);
	if(b)d=(d+3)%4;else d=(d+1)%4;
	printf(" l%d,%d",dir[d][0],dir[d][1]);
	hilbert(l,!b);
	if(b)d=(d+1)%4;else d=(d+3)%4;
}
int main(){
	freopen("output.svg","w",stdout);//固定输出文件名为output.svg
	printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");//svg文件头
	printf("<path d=\"M0.5,0.5");//起点
	hilbert(n,0);//6阶希尔伯特曲线
	printf("\" fill=\"none\" stroke=\"black\" stroke-width=\"0.1\"/>");//不填充,黑色线条,粗细为0.1
	printf("<path d=\"M0,0 l%d,0 l0,%d l%d,0 Z\" fill=\"none\" stroke=\"black\" stroke-width=\"0.1\"/>",pow(2,n),pow(2,n),-pow(2,n));//外框
	printf("</svg>");//svg文件尾
	return 0;
}
