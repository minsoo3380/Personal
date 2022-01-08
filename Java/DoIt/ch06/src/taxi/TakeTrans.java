package taxi;

public class TakeTrans {
	public static void main(String[] args) {
		Student studentEdward = new Student("Edward", 30000);
		studentEdward.showInfo();

		Taxi taxi3090 = new Taxi("3090");
		taxi3090.showInfo();

		studentEdward.takeTaxi(taxi3090);
		taxi3090.showInfo();

		studentEdward.takeAwayTaxi(taxi3090, 10000);
		studentEdward.showInfo();
		taxi3090.showInfo();
	}
}
