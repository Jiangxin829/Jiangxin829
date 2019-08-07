package First.characters;

import First.behavior.*;
/**
 * 
 * @author dell
 *
 */
public abstract class Characters {
	private String name;
//	private int hitPoint;
//	private int magicPoint;
//	private int damage;
//	private int defense;
    WeaponBehavior weapon;
    MagicBehavior magic;
    /**
     * 
     * @param name
     */
	public Characters(String name){
		this.name=name;
	}
	/**
	 * 
	 * @param c
	 */
	public void fight(Characters c){
		System.out.print(name+" ");
		weapon.weapon();
		System.out.println("  attack  "+c.name);
		
	}
	/**
	 * 
	 * @param c
	 */
	public void performMagic(Characters c){
		System.out.print(name+" ");
		magic.magic();
		System.out.println(" "+c.name);
	}
	/**
	 * 
	 * @param w
	 */
	public void setWeaponBehavior(WeaponBehavior w){
		weapon = w;
	}
	/**
	 * 
	 * @param m
	 */
    public void setMagicBehavior(MagicBehavior m){
    	magic=m;
	}
    /**
     * 
     * @return name
     */
	public String getName(){
		return name;
	}
	/**
	 * 
	 */
	public abstract void display();

}
