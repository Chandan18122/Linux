int main(){
	char buf[30];
	int n;
	write(1,"This is write to fd number 1\n",31);
	write(1,"enter a line of text\n",21);
	n = read(0,buf,80);
	write(1,"Following is the line i read\n",29);
	write(1,buf,n);
}
