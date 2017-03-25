class Class
{
	public:
		virtual void power() = 0;
		void draw();
		int cards_remaining();
	protected:
		int deck = 30;
		int armor = 0;
		int fatigue = 0;
		int health = 30;
};