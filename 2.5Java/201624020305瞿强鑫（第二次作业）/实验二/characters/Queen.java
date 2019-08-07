package First.characters;

import First.behavior.*;
/**
 * 
 * @author dell
 *
 */
public class Queen extends Characters{
	/**
	 * 
	 * @param name
	 */
	public Queen(String name){
		super(name);
		weapon = new BowAndArrowBehavior(); 
		magic = new HealBehavior();

	}
	/**
	 * 
	 */
	public void display(){
		System.out.print("I am Queen  "+getName()+" I ");
		magic.magic();
		System.out.println();
	}
}
