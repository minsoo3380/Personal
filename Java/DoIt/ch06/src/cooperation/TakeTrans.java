package cooperation;

public class TakeTrans {
	public static void main(String[] args) {
		Student studentJames = new Student("James", 5000);
		Student studentTomas = new Student("Tomas", 10000);
		studentJames.showInfo();
		studentTomas.showInfo();

		// James
		Bus bus100 = new Bus(100);
		bus100.showInfo();

		studentJames.takeBus(bus100);
		studentJames.showInfo();
		bus100.showInfo();

		// Tomas
		Subway subwayGreen = new Subway("2호선");
		subwayGreen.showInfo();

		studentTomas.takeSubway(subwayGreen);
		studentTomas.showInfo();
		subwayGreen.showInfo();
	}
}
