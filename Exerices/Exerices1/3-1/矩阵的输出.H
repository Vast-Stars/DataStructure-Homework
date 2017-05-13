//¾ØÕóµÄÊä³ö.h
void output(datatype x[][n])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<setw(5)<<x[i][j]; 
		cout<<endl;
	}
}

