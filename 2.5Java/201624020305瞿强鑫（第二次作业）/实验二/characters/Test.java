package First.characters;

import First.behavior.BowAndArrowBehavior;
import First.behavior.InvisibleBehavior;

public class Test {
	public static void main(String args[]){
		
		King k=new King("Tom");
		Queen q=new Queen("Marry");
		Knight kn=new Knight("Jack");
		Troll t=new Troll("Alice");
		k.display();
		q.display();
		kn.display();
		t.display();
		kn.performMagic(t);
		kn.performMagic(kn);
		k.fight(q);	
		System.out.println("�ı����k��������");
		k.setWeaponBehavior(new BowAndArrowBehavior());
		k.display();
		k.fight(q);	
		System.out.println("�ı�����q��ħ����");
		q.setMagicBehavior(new InvisibleBehavior());
		q.display();
	}

}
