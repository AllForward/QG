package stackpassage;

class LinkStack<T>{
    //栈顶节点
    private LinkNode<T> top;
    
    //初始化1
    public LinkStack(){
        this.top = new LinkNode<T>();
    }
    
    //初始化栈
    public void initStack(){
        this.top.setData(null);
        this.top.setNext(null);
    }
    //是否栈空
    public boolean isNull(){
        boolean flag = top.getNext()==null?true:false;
        return flag;
    }
    
    //压栈
    public void push(LinkNode<T> node){
        if(isNull()){
            //栈空，即第一次插入
            top.setNext(node);
            node.setNext(null);//该句可以省略(首次插入的元素为栈底元素)
        }else{
            node.setNext(top.getNext());
            top.setNext(node);
        }
    }
    
    //弹栈
    public LinkNode<T> pop(){
        if(isNull()){
            //栈空无法弹栈
            return null;
        }else{
            LinkNode<T> delNode = top.getNext();//取出删除节点
            top.setNext(top.getNext().getNext());//删除节点
            return delNode;
        }
    }
}


//链式栈节点（外部类实现，也可以使用内部类）
class LinkNode<T>{
    private T data;//数据域
    private LinkNode<T> next;//指针域
    
    //初始化1
    public LinkNode(){
        this.data = null;
        this.next = null;
    }
    
    //初始化2
    public LinkNode(T data) {
        super();
        this.data = data;
        this.next = null;
    }
    public T getData() {
        return data;
    }
    public void setData(T data) {
        this.data = data;
    }
    public LinkNode<T> getNext() {
        return next;
    }
    public void setNext(LinkNode<T> next) {
        this.next = next;
    }
}
class judge 
{
	public int Priority(char s) {		//判断运算符的优先级 
		switch(s)
		{
			case '(':
				return 3;
			case '*':
			case '/':
				return 2;
			case '+':
			case '-':
				return 1;
			default:
				return 0;			
		}
	}
	
	public int Judgecircle(int len,char[] circle)		//判断输入的算术表达式是否正确 
	{
		int i;
	    int t = 0;
	    int acc=0,bcc=0;
	    for(i=len-1;i>=0;i--){        
			if(circle[i]==')')            
				bcc++;        
			else if(circle[i]=='(')  
				acc++;
			if(circle[i]>=48&&circle[i]<=58)
				t = 1;}
		if(t == 0)return 1;			
		if(acc!=bcc){
	        return 1;
	    }
	    int toppei=0;
	    i=0;	
		while(i<len){
	        if(circle[i]=='('){
	            toppei++;
	        }
			if(circle[i]==')'&&toppei>=0){
	            toppei--;
	            i++;
	            continue;
	        }	
			else if(circle[i]==')'&&toppei==0)
	            return 1;
	        i++;
	    }    
	    if(toppei != 0)
	        return 1;
	    if(circle[0]=='.'||circle[len-1]=='=')return 1;
	    if((circle[0]<48||circle[0]>57)&&circle[0]!='-'&&circle[0]!='(')
	    	return 1;
	    if(circle[len-1]=='+'||circle[len-1]=='-'||circle[len-1]=='*'||circle[len-1]=='/'||circle[len-1]=='.')  
			return 1; 		
	    for(i=0;i<len;i++){ 
			if((circle[i]<48||circle[i]>57)&&(circle[i]!='+'&&circle[i]!='-'&&circle[i]!='*'&&circle[i]!='/'&&
				circle[i]!='('&&circle[i]!=')'&&circle[i]!='.'))
				return 1;    
			else if(circle[i]=='.'){
				if(circle[i+1]=='+'||circle[i+1]=='-'||circle[i+1]=='*'||circle[i+1]=='/'||circle[i+1]=='.'
				||circle[i+1]==')'||circle[i+1]=='(')
				return 1;
			}	  
			else if(circle[i]=='.'||circle[i]=='+'||circle[i]=='-'||circle[i]=='*'||circle[i]=='/'){   
				if(circle[i+1]=='+'||circle[i+1]=='-'||circle[i+1]=='*'||circle[i+1]=='/'||circle[i+1]=='.'||circle[i+1]==')')                
				return 1;}	
			if(circle[i]==')'){            
				if(circle[i+1]=='(')              
					return 1;}        
			if(circle[i]=='('){            
				if(circle[i+1]==')')                
					return 1;}	
		} 
		return 0;  
	}	
}
