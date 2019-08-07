package First.characters;

import First.behavior.*;
/**
 * 
 * @author dell
 *
 */
public class Troll extends Characters{
	/**
	 * 
	 * @param name
	 */
	public Troll(String name){
		super(name);
		weapon = new AxeBehavior(); 
		magic = new InvisibleBehavior();

	}
	/**
	 *  
	 */
	public void display(){
		System.out.print("I am Troll  "+getName()+" I ");
		weapon.weapon();
		System.out.println();
	}
}