#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int linknum=16;
int maxi=10;
float wpace=0.01f;
float bpace=0.1f;
float wx=1.3f;
float bx=10.0f;
int iz=9;
int oz=1;
int amt = 100; 
float snp = 0.2f;
float inz[9]={0,0,3,1,4,5,0,4,1};
int ouz=0;
FILE *fp;
	



class grdnode{
public:
	float w[32];
	float b;
	float opp;
	float ops;
	bool isStop;
	void init(int pian);
};

grdnode * nodes;



void grecord()
{
//	time_t t;
 //   struct tm * lt;
//    time (&t);//获取Unix时间戳。
 //   lt = localtime (&t);//转为时间结构。
//    fprintf (fp, "====%d/%d/%d %d:%d:%d====\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
	fprintf(fp,"\n");
	for(int i=0;i<amt;i++)
	{
		for(int j=0;j<linknum;j++)
		{
			fprintf(fp,"%.2f ",nodes[i].w[j]);
		}
	
		fprintf(fp,"%.2f ",nodes[i].b);
		fprintf(fp,"%d ",nodes[i].isStop);
		fprintf(fp,"%.2f \n",nodes[i].ops);
	}
//	fprintf(fp,"=======================================\n");
	fprintf(fp,"\n");
}



void nodesin()
{
	
	for(int i=0;i<iz;i++)
	{
		nodes[i].ops=inz[i];
	}

}

void grdmap()
{
	printf("map: init start\n");
	nodes = new grdnode[amt];
	for(int i=0;i<amt;i++)
	{
		nodes[i].init(i);
//		printf("node[%d],init finish\n",i);
	}
//	nodesin();
	printf("map: init finish\n");

}
void grdnode::init(	int pian ){
	float cs=1/snp;
	srand((unsigned)time(NULL)+pian);
	for(int i=0;i<linknum+1;i++){
		w[i]=(float)(rand()%1001)/1001;
		opp=ops=b=0;
	}
	w[0]=w[16];
	if(rand()%(int)cs==0)isStop=true;
	else isStop=false;
	if(rand()%(int)2==0)isStop=!isStop;


}

void map_run()
{
	double ssum=0.0;
	for(int i=0;i<amt;i++)
	{
		nodes[i].opp=nodes[i].ops;
		for(int j=(i-linknum+amt)%amt,k=0;k<linknum;k++)
		{
//			printf("%d\n",j);
			nodes[i].ops+=nodes[i].w[k]*nodes[j].ops;
			j=(j+1)%amt;
		}
		nodes[i].ops+=nodes[i].b;
		if(nodes[i].isStop)nodes[i].ops=-nodes[i].ops;
		if((nodes[i].isStop && nodes[i].ops>0)||(nodes[i].isStop==false && nodes[i].ops<0))nodes[i].ops=0;
		if(nodes[i].ops>0)nodes[i].b=nodes[i].b-bpace;
		else if(nodes[i].ops<0)nodes[i].b=nodes[i].b+bpace;
		nodes[i].ops=maxi*tanh(nodes[i].ops);
		for(j=(i-linknum)%amt,k=0;k<linknum;k++)
		{
			if((nodes[i].isStop==false && nodes[i].ops>0) &&(nodes[j].isStop==false && nodes[j].ops>0))nodes[i].w[k]+=wpace;
			else if((nodes[i].isStop==false && nodes[i].ops>0) &&(nodes[j].isStop==true && nodes[j].ops<0))nodes[i].w[k]+=wpace;
			else if((nodes[i].isStop==true && nodes[i].ops<0) &&(nodes[j].isStop==false && nodes[j].ops>0))nodes[i].w[k]+=wpace;
			else if((nodes[i].isStop==true && nodes[i].ops<0) &&(nodes[j].isStop==true && nodes[j].ops<0))nodes[i].w[k]+=wpace;
			else if(nodes[i].ops==0|| nodes[j].ops==0);
			else nodes[i].w[k]-=wpace;
			if(nodes[i].w[k]<=0)nodes[i].w[k]=0.02f;
			else if(nodes[i].w[k]>wx)nodes[i].w[k]=wx;	
			j=(j+1)%amt;
		}
		if(nodes[i].b<-bx)nodes[i].b=-bx;
		else if(nodes[i].b>bx)nodes[i].b=bx;
		ssum+=abs(nodes[i].ops);
	}
	fprintf(fp,"%f\n",ssum);

}
void seepara()
{
	for(int i=0;i<amt;i++)
	{
		for(int j=0;j<linknum;j++)
		{
			printf("%.2f ",nodes[i].w[j]);
		}
	
		printf("%.2f ",nodes[i].b);
		printf("%d ",nodes[i].isStop);
		printf("%.2f \n",nodes[i].ops);
	}
	printf("\n");
}
void seeparaone(int i=0)
{
	for(int j=0;j<linknum;j++)
	{
		printf("%.2f  ",nodes[i].w[j]);
	}
	
	printf("%.2f  ",nodes[i].b);
	printf("%d  ",nodes[i].isStop);
	printf("%.2f\n",nodes[i].ops);
	
}
void nodeout()
{
	
	for(int i=ouz;i<amt;i++)
	{
		seeparaone(i);
	}

}

int main()
{
	
	fp=fopen("record.txt","w");
	printf("record.txt open\n");
/**/	
	grdmap();
	for(int i=0;i<1000;i++)
	{
/*
		for(int j=0;j<10;j++)
		{
			

			seeparaone();
		}*/
//		nodesin();
		map_run();
//		grecord();
		
	}
	fclose(fp);
	fp=NULL;
	printf("record.txt close\n");
	printf("your can see data in record.txt\n");

	return 0;
}