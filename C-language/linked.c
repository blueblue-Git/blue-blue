/*
    链表的常用方法
author:　blueblue
email : 978897910@qq.com 
*/

/*
1:　经过XX条件，想要在一个链表特定的位置插入一个新的节点\
Node *current : 想要插入链表的收个节点地址
int new_value ： 插入的值     
 !!!!!!!!此函数有些问题： 当插入的地方在开头和结尾处，就有些不适用了!!!!!!!
*/
int sll_insert( Node *current，int new_value)
{
	Node *previous;
	Node *new;
	
	/*寻找正确的位置，并保存相应位置的节点地址和此节点下一个跳转地址*/
	while( (current-> value < new_value) && current != NULL)
	{
		 previous = current; //保存当前的节点地址
		 current  = current->link; //调转到下一个节点  
	}//end while  根据特定的条件就是要找到合适的节点地址和此节点中的link地址
	 //插入的时候就将新节点的链接地址赋值为current ,previous的地址就复制为新节点地址
	 
	 new = MALLOC(1,Node);
	 
	 new->value = new_value;
	 
	 new->link = current;
	 previous->link = new;
	 
}

/*
2:　解决1所带来的不适
    解决方法：把一个指向根节点的指针传递给参数，使用间接访问
	**roottp: 指向根节点的双重指针  ；2 还可以继续优化-->3
*/
int sll_insert( Node **roottp，int new_value)
{
	Node *previous;
	Node *new;
	Node *current;
	
	/*得到指向第一个节点的指针*/
	current = *roottp；
	previous = NULL;
	
	/*寻找正确的位置，并保存相应位置的节点地址和此节点下一个跳转地址*/
	while( (current-> value < new_value) && current != NULL)
	{
		 previous = current; //保存当前的节点地址
		 current  = current->link; //调转到下一个节点  
	}
	 
	 new = MALLOC(1,Node);
	 
	 new->value = new_value;
	 
	 
	 //将新的节点插入链表中
	 new->link = current;
	 if( previous == NULL)
	 {
	      *roottp = new;
	 }else
	 {
	      previous->link = new;	 
	 }
}
	 
/*
3:　在C语言中，还可以继续的优化
    优化方向: *linkp    开始指向根地址，然后每次跟进的时候，都指向当前的节点link的内容
	**linkp: 指向根节点的指针 ；加入register 可以加快访问速度
*/
int sll_insert( register Node **linkp，int new_value)
{
    register Node *new;
	register Node *current;  
	
	
	/*寻找正确的位置，并保存相应位置的节点地址和此节点下一个跳转地址*/
	while(  (current = *linkp) != NULL  &&  (current-> value < new_value) )
	{ 
		 linkp = &current->link; 
	}//end while   此时*linkp就是当前节点link中的内容
	 
	 new = MALLOC(1,Node);
	 
	 new->value = new_value;
	 
	 
	 //将新的节点插入链表中
	 new->link = current;
	 *linkp = new;
}	// 最后，对于插入一个节点，所需要的就是上一个节点所对应的link值；；
    // 然后new-link值= *link; *link = new； 通过交叉的一个替换就完成了新值的插入
	
/*
双链表： 每个节点都有两个指针，指向前一个节点和指向后一个节点，
         根节点一个指向第一个节点，另一个指向最后一个节点
		 第一个节点的bwd和最后一个节点的fwd为空
		 一般根节点的值字段是不被使用的
*/
	
