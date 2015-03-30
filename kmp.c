//在进行子字符串（从0记）i位对应的next数组值求解的时候  就是对比i-1位的字符与i-1位对应的next[i-1]的值所对应的字符
//进行对比  如果相同则 next[i]=next[i-1]+1;    如果不同则是将i-1位的字符与next[i-1]对应的字符的对应的next值的对应字符
//相互比较  重复过程，最终都没有匹配的话  就是next值为-1  这时就将这个值加1  
void GetNext(char*key,int *next){
	int length=strlen(key);
	int i=0;
	int k=-1;
	next[0]=-1;
	while(i<length-1){//因为
		if(k==-1||key[k]==key[i])
			{
			k++;i++;
			next[i]=k;
			}
		else
			{
			k=next[k];
			}
	}
}
int  KmpSerach(char* dat,char*key){
	int len_dat=strlen(dat);
	int len_key=strlen(key);
	int *next=(int*)malloc((len_key+1)*sizeof(int));
	int i=0,j=0;
	if(!next){
		exit(-1);
	}
	GetNext(key,next);
	while(i<len_dat&&j<len_key){
		if(j==-1||dat[i]==key[j]){
			i++;j++;
		}
		else{
			j=next[j];
		}
	}
	return j==len_key?i-j:-1;
}
