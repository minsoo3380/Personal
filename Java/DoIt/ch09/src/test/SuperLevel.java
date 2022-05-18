package test;

public class SuperLevel extends PlayerLevel {
	@Override
	public void run() {
		System.out.println("아주 힘차게 앞으로 달립니다.");
	}

	@Override
	public void jump() {
		System.out.println("아주 멀리 점프를 합니다.");
	}

	@Override
	public void turn() {
		System.out.println("360도 턴을 갈겨버립니다.");
	}

	@Override
	public void showLevelMessage() {
		System.out.println("=== 고급자 레벨입니다. ===");
	}
}
