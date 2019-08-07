package First.characters;

import First.behavior.*;
/**
 * 
 * @author dell
 *
 */
public class King extends Characters{
	/**
	 * 
	 * @param name
	 */
	public King(String name){
		super(name);
		weapon = new KnifeBehavior(); 
		magic = new HealBehavior();

	}
	/**
	 *  
	 */
	public void display(){
		System.out.print("I am King  "+getName()+" I ");
		weapon.weapon();
		System.out.println();
	}

}
