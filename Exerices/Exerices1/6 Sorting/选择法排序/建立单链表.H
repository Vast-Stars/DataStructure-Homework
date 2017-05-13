//建立单链表.h
linklist*creat()
{  datatype x;
   linklist *s,*r,*h=new linklist;
   r=h;
   cin>>x;
   while(x!=-1)
   {  
	  s=new linklist;
      s->key=x;
	  r->next=s;
	  r=s;
	  cin>>x;
   }
   r->next=NULL;
   return h;
}