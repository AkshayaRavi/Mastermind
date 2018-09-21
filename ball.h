class Ball
{
    public:
        Ball();
        Ball(char colo,int posi);
        int getcolor();
        int getposition();
        int setcolor(char colo);
        int setposition(int posi);

    protected:

    private:
        	char color;
            int position;
};

Ball::Ball()
	{
		color='0';
		position=1;
	}
Ball::Ball(char colo,int posi)
	{
		color=colo;
		position=posi;
	}
int Ball::getcolor()
	{
		return color;
	}
int Ball::getposition()
	{
		return position;
	}
int Ball::setcolor(char colo)
	{
		color=colo;
	}
int Ball:: setposition(int posi)
	{
		position=posi;
	}
