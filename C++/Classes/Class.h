class Class
{
	public:
		virtual void power() = 0;
		void draw();
		int cards_remaining();
		int damage(int damage_taken);
		int get_health();
		//Called after each damaging action
		bool isAlive();
		int get_fatigue();
	protected:
		int deck = 30;
		int armor = 0;
		int fatigue = 0;
		int health = 30;
};