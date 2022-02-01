package practice;

public class DogTest {
	public static void main(String[] args) {
		Dog[] dogs = new Dog[5];

		dogs[0] = new Dog();
		dogs[0].setName("힌둥이");
		dogs[0].setType("하얀개");

		dogs[1] = new Dog();
		dogs[1].setName("검둥이");
		dogs[1].setType("검은개");

		dogs[2] = new Dog();
		dogs[2].setName("누렁이");
		dogs[2].setType("누런개");

		dogs[3] = new Dog();
		dogs[3].setName("파랑이");
		dogs[3].setType("파란개");

		dogs[4] = new Dog();
		dogs[4].setName("강산이");
		dogs[4].setType("진돗개");

		for(Dog dog : dogs) {
			System.out.println(dog.showDogInfo());
		}

		DogTestArrayList dogList = new DogTestArrayList();
		dogList.addDogList("흰중주으", "그런종");
		dogList.addDogList("검둥이요", "검은종");
		dogList.showDogsInfo();
	}
}
