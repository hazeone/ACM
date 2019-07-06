#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	double n[50], n0, nn, t, tk, Mk, Ek, Vk, Yk, Gu, Gr, Gi, uk, rk, ik, xk, yk,zk, X, Y, Z, Lk, UT, yy, mm, JD, gpsz;
	FILE *fp;
	fp = fopen("F:\\单一卫星广播星历.txt", "r");
	if (fp == NULL)
	{
		printf ("文件打开失败!\n");
		return 0;
	}
	while (! feof (fp))
	{
		fscanf(fp, "%lf", &n[i]);
		i++;
	}
	n0=(sqrt(3986005E+8))/pow(n[17],3);
	nn= n0+n[12];/*计算卫星运行的平均角速度*/
	UT=n[4]+(n[5]/60)+(n[7]/3600);/*民用日的时分秒化为实数时*/
	if (n[1] >= 80)/*广播星历中年只有后两位，化为4位，参考1980年1月6日0点*/
	{
		if (n[1] == 80 && n[2] == 1 && n[3] < 6)
		{
			n[1] = n[1] + 2000;
		}
		n[1] = n[1] + 1900;
	}
	else
	{
		n[1] = n[1] + 2000;
	}
	if (n[2] <= 2)
	{
		yy = n[1] - 1;
		mm = n[2] + 12;
	}
	if (n[2] > 2)
	{
		yy = n[1];   mm = n[2];
	}
	JD = (int)(365.25 * yy) + (int)(30.6001 * (mm + 1)) + n[3] + (UT / 24) + 1720981.5;/*化为儒略日*/
	gpsz = (int)((JD - 2444244.5) / 7);/*计算GPS周*/
	t = (JD - 2444244.5 - 7 * gpsz) * 24 * 3600;/*得出GPS秒*/
	tk = t - n[18];/*tk1为中间值，用以判断tk与正负302400的关系，然后返回到tk上*/
	while (tk > 302400 || tk < -302400)
	{
		if (tk > 302400)
		{
			tk = tk - 604800;
		}
		else
		{
			tk = tk + 604800;
		}
	}/*计算归化观测时间*/
	Mk = n[13] + nn * tk;/*观测时刻的卫星平近点角*/
	Ek = Mk;
	Ek = Mk + n[15] * sin(Ek);
	Ek = Mk + n[15] * sin(Ek);/*迭代两次计算观测时刻的偏近点角*/
	Vk=atan(sqrt(1-n[15]* n[15]* sin(Ek))/(cos(Ek)-n[15]));/*真近点角*/
	Yk=Vk+n[24];/*升交距角*/
	Gu=n[14]*cos(2*Yk)+n[16]*sin(2*Yk);
	Gr=n[23]*cos(2*Yk)+n[11]*sin(2*Yk);
	Gi=n[19]*cos(2*Yk)+n[21]*sin(2*Yk);/*摄动改正项*/
	uk=Yk+Gu;
	rk=n[17]*n[17]*(1-n[15]*cos(Ek))+Gr;
	ik=n[22]+Gi+n[26]*tk;/*经摄动改正后的升交距角、卫星矢径、轨道倾角*/
	xk=rk*cos(uk);
	yk=rk*sin(uk);
	zk=0;/*卫星在轨道坐标系的坐标*/
	Lk=n[20]+(n[25]-7.29211515E-5)*tk-7.29211515E-5*n[18];/*观测时刻t的升交点经度*/
	X=xk*cos(Lk)-yk*cos(ik)*sin(Lk);
	Y=xk*sin(Lk)+yk*cos(ik)*cos(Lk);
	Z=yk*sin(ik);/*卫星在WGS-84坐标系的坐标*/
	printf("该卫星在WGS-84坐标系中的坐标为:\nX = %lf m\nY = %lf m\nZ = %lf m\n",X,Y,Z);
	fclose(fp);
	return 0;
}
