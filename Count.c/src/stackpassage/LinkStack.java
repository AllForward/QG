package stackpassage;

class LinkStack<T>{
    //ջ���ڵ�
    private LinkNode<T> top;
    
    //��ʼ��1
    public LinkStack(){
        this.top = new LinkNode<T>();
    }
    
    //��ʼ��ջ
    public void initStack(){
        this.top.setData(null);
        this.top.setNext(null);
    }
    //�Ƿ�ջ��
    public boolean isNull(){
        boolean flag = top.getNext()==null?true:false;
        return flag;
    }
    
    //ѹջ
    public void push(LinkNode<T> node){
        if(isNull()){
            //ջ�գ�����һ�β���
            top.setNext(node);
            node.setNext(null);//�þ����ʡ��(�״β����Ԫ��Ϊջ��Ԫ��)
        }else{
            node.setNext(top.getNext());
            top.setNext(node);
        }
    }
    
    //��ջ
    public LinkNode<T> pop(){
        if(isNull()){
            //ջ���޷���ջ
            return null;
        }else{
            LinkNode<T> delNode = top.getNext();//ȡ��ɾ���ڵ�
            top.setNext(top.getNext().getNext());//ɾ���ڵ�
            return delNode;
        }
    }
}


//��ʽջ�ڵ㣨�ⲿ��ʵ�֣�Ҳ����ʹ���ڲ��ࣩ
class LinkNode<T>{
    private T data;//������
    private LinkNode<T> next;//ָ����
    
    //��ʼ��1
    public LinkNode(){
        this.data = null;
        this.next = null;
    }
    
    //��ʼ��2
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
	public int Priority(char s) {		//�ж�����������ȼ� 
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
	
	public int Judgecircle(int len,char[] circle)		//�ж�������������ʽ�Ƿ���ȷ 
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
