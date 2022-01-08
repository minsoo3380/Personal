class Date{
	private int year;
	private int month;
	private int day;

	public Date(){
		year = 1990;
		month = 1;
		day = -1;
	}

	public Date(int yy, int mm, int dd){
		setDate(yy, mm, dd);
	}

	public void setDate(int yy, int mm, int dd){
		int[] days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		year = max(1990, yy);
		month = max(1, mm);
		month = min(month, 12);

		// 윤년 ㄱㅖ산은 생략함
		day = max(1, dd);
		day = min(day, days[month]);
	}

	public void displayDate(){
		//System.out.println(year + "-" + month + "-" + day);
		System.out.printf("%4d-%02d-%02d\n", year, month, day);
	}

	private int min(int x, int y){
		if(x < y)
			return x;
		return y;
	}
	
	private int max(int x, int y){
		if(x > y)
			return x;
		return y;
	}
}
