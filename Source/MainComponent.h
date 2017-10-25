/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component, 
	public TextEditor::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

	// listener
	void textEditorTextChanged(TextEditor&) override;
	void textEditorReturnKeyPressed(TextEditor&) override;
	void textEditorEscapeKeyPressed(TextEditor&) override;
	void textEditorFocusLost(TextEditor&) override;

	String encrypt(const String&);

private:
    //==============================================================================
	ScopedPointer<TextEditor> inputEditor;
	ScopedPointer<TextEditor> outputEditor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
