package Second;

public class SortInterfaceTest {
	public static void main(String args[ ]) {
		int i;

		//����Point��������
		Point p[ ] = new Point[10];

		for( i=0; i<p.length; i++)
			p[i] = new Point(
					 (int)(Math.random( )*10),
					 (int)(Math.random( )*10)
					);
		
		System.out.println("��Point�����������"); 
		Sort.SelectSort( p );
		//��������Ķ���
		for( i=0;i<p.length;i++)
			System.out.println(p[i]);
		
		
		
		
		
		
		Student S[ ] = new Student[5];

		for( i=0; i<S.length; i++)
			S[i] = new Student(
					 "Student"+i,
					 (int)(Math.random( )*100)
					);
		
		System.out.println("��Student�����������"); 
		Sort.SelectSort( S );
		//��������Ķ���
		for( i=0;i<S.length;i++)
			System.out.println(S[i]);
		
		
		
		
		Triangle T[ ] = new Triangle[10];

		for( i=0; i<T.length; i++)
			T[i] = new Triangle(
					new Point(
							 (int)(Math.random( )*10),
							 (int)(Math.random( )*10)
							),
					new Point(
							 (int)(Math.random( )*10),
							 (int)(Math.random( )*10)
							),
					new Point(
							 (int)(Math.random( )*10),
							 (int)(Math.random( )*10)
							)
					
					);
		
		System.out.println("��Triangle�����������"); 
		Sort.SelectSort( T );
		for( i=0;i<T.length;i++)
			System.out.println(T[i]);

	}
}
