#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

class HelloWorldApp : public wxApp
{
public:
	// virtual bool OnInit() wxOVERRIDE;
	virtual bool OnInit();
};

DECLARE_APP(HelloWorldApp)

#endif // INCLUDED_HELLOWORLDAPP_H
