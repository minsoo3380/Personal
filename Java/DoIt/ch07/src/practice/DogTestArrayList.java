package practice;

import java.util.ArrayList;

public class DogTestArrayList {
	private ArrayList<Dog> dogList = new ArrayList<Dog>();

	public void addDogList(String name, String type) {
		Dog dog = new Dog();
		dog.setName(name);
		dog.setType(type);
		dogList.add(dog);
	}

	public void showDogsInfo() {
		for(Dog dog : dogList) {
			System.out.println("Dog Name : " + dog.getName() + ", Dog Type : " + dog.getType());
		}
	}
}
