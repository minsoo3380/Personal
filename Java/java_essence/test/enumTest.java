class enumTest {
	private enum saperate {PRE, DEF};

	public enumTest(String param) {
		T(param);
	}

	public void T(String param) {
		System.out.println("param : " + param);
		System.out.println("sap : " + saperate.PRE);
		if(param.equals("PRE"))
			System.out.println(saperate.PRE);
		else
			System.out.println("else");
	}

	public static void main(String[] args) {
		enumTest et = new enumTest(args[0].toString());
	}
}
