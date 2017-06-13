void postOrder2(Tree *root)    //非递归后序遍历
{
    stack s;
    Tree *p = root;
    BTNode *temp;
    while (p != NULL || !s.empty())
    {
        while (p != NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点
        {
            BTNode *btn = (BTNode *) malloc(sizeof(BTNode));
            btn->btnode = p;
            btn->isFirst = true;
            s.push(btn);
            p = p->lchild;
        }
        if (!s.empty())
        {
            temp = s.top();
            s.pop();
            if (temp->isFirst == true)     //表示是第一次出现在栈顶
            {
                temp->isFirst = false;
                s.push(temp);
                p = temp->btnode->rchild;
            }
            else                        //第二次出现在栈顶
            {
                cout << temp->btnode->data << " ";
                p = NULL;
            }
        }
    }
}