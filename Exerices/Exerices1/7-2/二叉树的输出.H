//�����������.h
void preorder(bitree*p)
{
	if(p!=NULL)
	{
		cout<<p->key;
		if(p->lchild!=NULL||p->rchild!=NULL)
		{
			cout<<"(";
			preorder(p->lchild);
			if(p->rchild!=NULL)cout<<",";
			preorder(p->rchild);
			cout<<")";
		}
	}
}
