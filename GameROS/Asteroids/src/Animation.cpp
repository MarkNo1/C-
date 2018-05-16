//
// Created by mark on 16/05/18.
//

// Constructor
Animation::Animation(){};

// Constructor with parameters
Animation::Animation(sf::Texture &t, int x, int y, int w, int h, int count, float speed)
{
  frameNumber = 0;
  this->speed = speed;

  for (int i = 0; i < count; i++)
    frames.push_back(sf::IntRect(x + i * w, y, w, h));

  sprite.setTexture(t);
  sprite.setOrigin(w / 2, h / 2);
  sprite.setTextureRect(frames[0]);
}

// Update
void Animation::update()
{
  frameNumber += speed;
  int n = frames.size();
  if (frameNumber >= n)
    frameNumber -= n;
  sprite.setTextureRect(frames[(int)frameNumber]);
}

// is End
bool Animation::isEnd()
{
  return frameNumber + speed >= frames.size();
}
