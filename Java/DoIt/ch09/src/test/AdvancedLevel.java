package test;

public class AdvancedLevel extends PlayerLevel {
	@Override
	public void run() {
		System.out.println("힘차게 앞으로 달립니다.");
	}

	@Override
	public void jump() {
		System.out.println("앞으로 점프를 합니다.");
	}

	@Override
	public void turn() {
		System.out.println("턴을 아직 배우지 못했습니다.");
	}

	@Override
	public void showLevelMessage() {
		System.out.println("=== 중급자 레벨입니다. ===");
	}
}
