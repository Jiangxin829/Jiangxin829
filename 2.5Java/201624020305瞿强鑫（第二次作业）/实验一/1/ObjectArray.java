/*******************************************************************  
* Module:  ObjectArray.java<br>  
* Purpose: ����һ�����Դ�Ŷ���Ķ�̬����<br>  
* @author *** 
*******************************************************************/ 
public class ObjectArray {

    /** ���������ʼ��С */
    public final static int INIT_SIZE = 5;    
    
    /** �����������������С������ */  
    public final static int INCREASEMENT = 3;   
     
    /** �������� */  
    private Object[] data;    
    
    /** �����������Ѵ洢�Ķ������� */  
    private int size; 
       
    /** ���췽�� */  
    public ObjectArray() 
    {  
 
        data = new Object[INIT_SIZE];   
        size = 0;  
    }    
    
    /** �������������β��   
    *   @param o Ҫ��ӵĶ�������  */  
    
    public void add(Object o) { 
    
        if(size<data.length){
		    }
		    else{
			    Object[] temp=new Object[size+INCREASEMENT];
		      for(int i=0;i<size;i++){
				  temp[i]=data[i];
			  }
			    data=temp;
		}
		data[size++]=o;
  
    System.out.println(data.length);
  
    }    
 
     /** ���ص� i �����������   
     *   @param i �����±�Ϊ 0 ��Ӧ�� 1 ��Ԫ��  
     *   @return ���ص� i ����������ã���� i ���ںϷ���Χ�򷵻� null��   */  
     public Object get(int i) 
     { 
           if (i<1 || i>size)
           {
           	   return null;
           }
               return data[i-1];

     }    
     
     /** ɾ���� i ������  
     *   @param i �����±�Ϊ 0 ��Ӧ�� 1 ��Ԫ��  
     *   @return ���ص� i ����������ã���� i ���ںϷ���Χ�򷵻� null��  */  
     public Object remove(int i) { 
     	     if (i<1 || i>size)
           {
           	   return null;
           }
           Object o = data[i-1];
           for (int k = i-1; k < size - 1; k ++)
           {
              data [k] = data [k+1];
           }
           return o;
      }   
   
   
      /** ���ص�ǰ�����д洢�Ķ������  
      *   @return ���ص�ǰ�����д洢�Ķ��������  */  
      public int size() {    return size;  }    
      
      
      /** �����������鲢��� */  
      public void traverse() {    
          for (int i = 0; i<size; i++)
              {     
              System.out.println(data[i]);   
              }  
      }    
      
      public static void main(String args[]) 
      { 
            ObjectArray oa = new ObjectArray();
            
            String s1 = " hello ";
            String s2 = " world ";
            oa.add(s1);
            oa.add(s2);
            
            
            String s3 = " man ";
            oa.add(s3);
            
            String s0 = (String)oa.get(2);
            
            System.out.println(s0);
            
            System.out.println(oa.size());
            
            String s5 = "xiao";
            oa.add(s5);
            
            String s6 = "xiao";
            oa.add(s6);
            oa.add(s6); 
            oa.add(s6);
            oa.add(s6);
            oa.add(s6);
            oa.add(s6);
            oa.add("last");
            
            s0 = (String)oa.get(12);
            System.out.println(s0);
            oa.traverse();
            
            System.out.println(oa.remove(2));
            oa.traverse();
 

 
       }   
} 