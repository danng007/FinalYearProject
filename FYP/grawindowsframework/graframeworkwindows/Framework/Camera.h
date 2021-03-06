
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Camera
{
public:
	Camera();
    ~Camera(void);
    
	// These functions can be called to get the position/view direction/camera axis of the camera in world space
    void GetEyePosition( float &x, float &y, float &z) const;
    void GetViewDirection( float &x, float &y, float &z) const;
    void GetForwardVector( float &x, float &y, float &z) const;
    void GetRightVector( float &x, float &y, float &z) const;
    void GetUpVecotor( float &x, float &y, float &z) const;
    
	char(*file)[100];
    // Called each frame to update.
    void Update( const double& deltaTime );
    
    // Called when a key is pressed - x and y are the mouse coordinates at the time when key is pressed
    void HandleKey(int key, int state, int x, int y );
    
    // Called when a mouse button is pressed, or released - x and y are the mouse position.
    void HandleMouseClick( int button, int state, int x, int y );
    
    // Called when the mouse moves if a button is pressed - x and y are the mouse position.
    void HandleMouseMotion( int x, int y );
    
    // Called every time the mouse moves - x and y are the mouse position.
    void HandlePassiveMouseMotion( int x, int y );
    
    // Called each time the window is resized to make sure the aspect ratio is correct.
    void SetViewport( const int& width, const int& height );
	void GetBuffer(char buffer[][100]);
    // Called each frame just before objects are drawn to set camera position, orientation, projection.
    void SetUpCamera();
private:

	/*void ReadFile1();
	void ReadFile2();
	void ReadFile3();*/
	ifstream myfile;
	static const int widthUnit = 8, heightUnit = 10; //widthUnit is height -.-
	/*char file1[100][100];
	char file2[100][100];
	char file3[100][100];*/
	char * fileNumber;
	// Member variable to keep track of the position of the camera in world space
    float eye[3];
	float preEye[3];
    // Member variable to keep track of the viewDirection, forward, up and right vectors of the camera
    float vd[3];
    float forward[3];
    float right[3];
    float up[3];
    
    // Member variable used to track when a key is pressed between frames
    // so that we can do an update in the Update() function rather than HandleKey function to obtain smooth motion
    int wKey, sKey, aKey, dKey;
    
    // Memeber variable to remember mouse details
    int currentButton;
    GLint mouseX, mouseY;

};



