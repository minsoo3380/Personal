package test;

public class BeginnerLevel extends PlayerLevel {
	@Override
	public void run() {
		System.out.println("앞으로 달립니다.");
	}

	@Override
	public void jump() {
		System.out.println("점프를 배우지 못했습니다.");
	}

	@Override
	public void turn() {
		System.out.println("턴을 아직 배우지 못했습니다.");
	}

	@Override
	public void showLevelMessage() {
		System.out.println("=== 초급자 레벨입니다. ===");
	}
}
