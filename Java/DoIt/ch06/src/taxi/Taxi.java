package taxi;

public class Taxi {
	String taxiNumber;
	String destination;
	int passengerCnt;
	int fee;
	int money;
	int balance;

	public Taxi(String taxiNumber) {
		this.taxiNumber = taxiNumber;
		this.destination = "";
		this.passengerCnt = 0;
		this.fee = 0;
		this.money = 0;
	}
	
	public void take(String destination) {
		this.destination = destination;
		this.passengerCnt++;
		this.departTaxi();
	}

	public int takeAway(int moneyByPassenger) {
		balance = moneyByPassenger - fee;
		passengerCnt--;
		this.money += fee;

		return balance;
	}

	public void showInfo() {
		System.out.println("택시번호 : " + taxiNumber + "승객수 " + passengerCnt + "  수입은 " + money + "입니다.");
	}

	private void departTaxi() {
		// 요금 증가 임시
		fee += 10000;
	}
}
