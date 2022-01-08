package taxi;

public class Student {
	String studentName;
	int money;
	int grade;

	public Student() {
		this("이름없음", 0);
	}

	public Student(String studentName, int money) {
		this.studentName = studentName;
		this.money = money;
	}

	public void takeTaxi(Taxi taxi) {
		taxi.take("광남역");
	}

	public void takeAwayTaxi(Taxi taxi, int fee) {
		if(fee > this.money) {
			System.out.println("소지금이 부족합니다.");
			return;
		}

		this.money -= fee;
		this.money += taxi.takeAway(fee);
	}

	public void showInfo() {
		System.out.println(studentName + " 에게 남은 금액은 " + money + "입니다.");
	}
}
