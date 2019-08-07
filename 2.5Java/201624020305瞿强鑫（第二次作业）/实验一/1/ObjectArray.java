/*******************************************************************  
* Module:  ObjectArray.java<br>  
* Purpose: 定义一个可以存放对象的动态数组<br>  
* @author *** 
*******************************************************************/ 
public class ObjectArray {

    /** 对象数组初始大小 */
    public final static int INIT_SIZE = 5;    
    
    /** 对象数组满后，数组大小的增量 */  
    public final static int INCREASEMENT = 3;   
     
    /** 对象数组 */  
    private Object[] data;    
    
    /** 对象数组中已存储的对象数量 */  
    private int size; 
       
    /** 构造方法 */  
    public ObjectArray() 
    {  
 
        data = new Object[INIT_SIZE];   
        size = 0;  
    }    
    
    /** 将对象加至数组尾部   
    *   @param o 要添加的对象引用  */  
    
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
 
     /** 返回第 i 个对象的引用   
     *   @param i 数组下标为 0 对应第 1 个元素  
     *   @return 返回第 i 个对象的引用，如果 i 不在合法范围则返回 null。   */  
     public Object get(int i) 
     { 
           if (i<1 || i>size)
           {
           	   return null;
           }
               return data[i-1];

     }    
     
     /** 删除第 i 个对象  
     *   @param i 数组下标为 0 对应第 1 个元素  
     *   @return 返回第 i 个对象的引用，如果 i 不在合法范围则返回 null。  */  
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
   
   
      /** 返回当前数组中存储的对象个数  
      *   @return 返回当前数组中存储的对象个数。  */  
      public int size() {    return size;  }    
      
      
      /** 遍历对象数组并输出 */  
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