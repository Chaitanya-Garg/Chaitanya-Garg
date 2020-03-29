#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct process{int id,at,bt,priority,ct,wt,tempd,tat,tempbt,tempp;};
struct process p[50], q[50];
int start = 0, end=0, time=0;
void Enter(struct process onep){
	q[end] = onep;
	end = end + 1;
	int i;
	for(i = start; i<end; i++)p[q[i].id].tempd = 1;
	}
void terminated(){
	int i;
	struct process temp;
	temp = q[start];
	for(i = start; i<=end-1; i++)q[i] = q[i+1];
	end = end - 1;}
int Display(int n, int k, int t){
		int i;
		printf("\n\n___________________________________________________________________\n\n PID\t-> \tAT\tBT\tPriority     TAT\tWT\tCT\n===================================================================");
		for (i = 0; i < n; i++){
			if(i<k)printf("\n P%d\t-> \t%d\t%d\t   %d\t      -\t\t-\t-",p[i].id,p[i].at,p[i].bt,p[i].priority);
			else printf("\n P%d\t-> \t-\t-\t   -\t      -\t\t-\t-",i);}
		printf("\n___________________________________________________________________\n");}
int show(int n, int t){
		int i;
		printf("\n\n\nConclusion:\n\n Processes in total (n) = %d\n\t   Time Quantum = %d\n___________________________________________________________________\n\n PID\t-> \tAT\tBT\tPriority     TAT\tWT\tCT\n___________________________________________________________________\n",n,t);
		for (i = 0; i < n; i++)printf("\n P%d\t-> \t%d\t%d\t   %d\t      %d      \t%d    \t%d",p[i].id,p[i].at,p[i].tempbt,p[i].tempp,p[i].tat,p[i].wt,p[i].ct);						
		printf("\n___________________________________________________________________\n");}
int max(int n, int k){
	if(k==1){
		int i,maximum,index;
		maximum = p[0].at;
		for(i=0;i<n;i++)if(p[i].at>maximum){				
				maximum=p[i].at;
				index = i;}return(p[index].id);}
	else if(k==2){
		int i,maximum;
		maximum = p[0].bt;
		for(i=0;i<n;i++)if(p[i].bt>maximum)maximum=p[i].bt;
		return(maximum);}
	else if(k==3){
		int i,maximum,index;
		maximum = q[0].priority;
		for(i=0;i<n;i++)if(q[i].priority>maximum){						
				maximum=q[i].priority;
				index = i;}return(q[index].id);}}
int min(int n, int k){
	if(k==1){
		int i,minimum,index;
		minimum = p[0].at;
		for(i=0;i<n;i++)if(p[i].at<minimum){						
				minimum=p[i].at;
				index = i;}return(p[index].id);}
	else if(k==2){
		int i,minimum;
		minimum = p[0].bt;
		for(i=0;i<n;i++)if(p[i].bt<minimum)minimum=p[i].bt;
		return(minimum);}
	else if(k==3){
		int i,minimum;
		minimum = p[0].priority;
		for(i=0;i<n;i++)if(p[i].priority<minimum)minimum=p[i].priority;
		return(minimum);}}
void sort(int n){
	int i, j;
	struct process temp;
	for(i = 0; i<n-1; i++)for(j = i+1; j<n; j++)if(p[i].at>p[j].at){
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;}
	for(i = 0; i<n; i++){
		p[i].id = i;
		p[i].tempd = 0;}}
void sortqueuepriority(){
	int i, j;
	struct process temp;
	for(i = 0; i<end-1; i++)for(j = i+1; j<end; j++)if(q[i].priority<q[j].priority){
				temp = q[i];
				q[i] = q[j];
				q[j] = temp;}}
int main(){
	int n,t,i,x,y,z,minatpid,maxprioritypid,totalbt = 0,j,k,count=0;
	float totalwt=0, totaltat=0, totalct=0,avgwt,avgtat,avgct;
	up:
	printf("\n Enter Total Number of Processes = ");
	scanf("%d",&n);
	printf("\n Enter Time Quantum = ");
	scanf("%d",&t);
	if((n<0)||(t<0)){
		system("cls");
		printf("___________________________________________________________________");
		printf("\n Invalid Entry\n");
		goto up;}
	printf("___________________________________________________________________\n\n PID\t-> \tAT\tBT\tPriority     TAT\tWT\tCT\n___________________________________________________________________\n");
	for (i = 0; i < n; i++)printf("\n P%d\t-> \t-\t-\t   -\t      -\t\t-\t-",i);
	printf("\n___________________________________________________________________\n\n");
	for ( i = 0; i < n; i++){
		printf("\n => PROCESS P%d \n________________\n\n Arrival Time : ",i+1);
		scanf("%d",&p[i].at);
		printf("\n Burst Time   : ");
		scanf("%d",&p[i].bt);
		p[i].tempbt = p[i].bt;
		printf("\n Priority     : ",i+1);
		scanf("%d",&p[i].priority);
		p[i].tempp = p[i].priority;
		if((p[i].at<0)||(p[i].bt<0)||(p[i].priority<0)){
				system("cls");
				printf("_______________________********_*******_____________________________");
				printf("\n Invalid Entry\n");
				goto up;}
		p[i].id=i;
		system("cls");
		Display(n,i+1,t);}
	system("cls");
	sort(n);
	printf("\nTABLE (after the arrangement):");
	Display(n,n,t);
	printf("\n\n\n");
	minatpid = min(n,1);
	for(i=0; i<n; i++)if(p[minatpid].at==p[i].at){
		Enter(p[i]);
		p[i].tempd==1;}
	maxprioritypid = max(end,3);
	for(i = 0; i<n; i++)totalbt = totalbt + p[i].bt;
    sortqueuepriority();
	printf("\n___S_C_H_E_D_U_L_E_R_-_P_R_O_G_R_A_M___O_U_T_P_U_T___R_E_S_U_L_T_S___\n\n\n");
	while(count!=n){
		count = 0;
		for(j = 0; j<n; j++)if((p[j].tempd==0)&&(p[j].at<=time))Enter(p[j]);
		sortqueuepriority();
		if((q[start].at!=0)&&(time==0)){
			printf("\n0 - %d -> No Process",q[start].at);
			time = time + q[start].at;}
		if(q[start].bt <= t){
			int oldtime = time;
			time = time + q[start].bt;
			p[q[start].id].bt = 0;
			q[start].bt = 0;
			if(q[start].priority!=0)q[start].priority = q[start].priority - 1;
			printf("\n%d - %d -> P%d \n\tBurst Left: %d",oldtime,time,q[start].id,p[q[start].id].bt);
			p[q[start].id].ct = time;
			p[q[start].id].tat = p[q[start].id].ct - p[q[start].id].at;
			p[q[start].id].wt = p[q[start].id].tat - p[q[start].id].tempbt;
			if(p[q[start].id].priority!=0)p[q[start].id].priority = p[q[start].id].priority - 1;
			terminated();}
		else{
			int oldtime = time;
			time = time + t;
			q[start].bt = q[start].bt - t;
			p[q[start].id].bt = p[q[start].id].bt - t;
			if(q[start].priority!=0)q[start].priority = q[start].priority - 1;
			struct process temp;
			temp = q[start];
			terminated();
			Enter(temp);
			printf("\n%d - %d -> P%d\n\tBurst Left: %d",oldtime,time,temp.id,temp.bt);
			temp.ct = time;
			temp.tat = temp.ct - temp.at;
			temp.wt = temp.tat - temp.tempbt;
			if(temp.priority!=0)temp.priority = temp.priority - 1;}
		printf("\n\tExecution Time: %d",time);
		for(k=0; k<n; k++)if(p[k].bt==0)count = count + 1;
		if(start==end){
			if(count==n)break;
			else{
				int lastat;
				lastat = max(n,1);
				int oldtime = time;
				time = p[lastat].at; 
				printf("\n%d - %d -> No process",oldtime,time);}}}
	printf("\n\n_______________________________________________________________________________________________");
	show(n,t);
	for(i = 0; i< n;i++){
		totalwt = totalwt + p[i].wt;
		totaltat = totaltat + p[i].tat;
		totalct = totalct + p[i].ct;}
	avgwt = totalwt/n;
	avgtat = totaltat/n;
	avgct = totalct/n;
	printf("\n\nAverage of :\n WT  = %f\n TAT = %f\n CT  = %f\n\n___***___***___***___***___***___***___***___***___***___***___***___***___***___***___***___***___***___***",avgwt,avgtat,avgct);}
