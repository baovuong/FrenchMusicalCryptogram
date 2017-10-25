/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
	// styling
	getLookAndFeel().setColour(ResizableWindow::backgroundColourId, Colour(0, 0, 0));
	getLookAndFeel().setColour(TextEditor::backgroundColourId, Colour(100, 100, 100));

	// widgets
	inputEditor = new TextEditor();
	inputEditor->setMultiLine(true);
	inputEditor->setReturnKeyStartsNewLine(true);
	inputEditor->addListener(this);
	
	outputEditor = new TextEditor();
	outputEditor->setMultiLine(true);
	outputEditor->setEnabled(false);

	addAndMakeVisible(outputEditor);
	addAndMakeVisible(inputEditor);

	// configuration
    setSize (600, 400);	
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	inputEditor->setBounds(10, 10, getWidth()/2 - 20, getHeight() - 20);
	outputEditor->setBounds(getWidth() / 2 + 10, 10, getWidth() / 2 - 20, getHeight() - 20);
}

void MainContentComponent::textEditorTextChanged(TextEditor & textEditor)
{
	outputEditor->setText(encrypt(textEditor.getText()));
}

void MainContentComponent::textEditorReturnKeyPressed(TextEditor & textEditor)
{
}

void MainContentComponent::textEditorEscapeKeyPressed(TextEditor & textEditor)
{
}

void MainContentComponent::textEditorFocusLost(TextEditor & textEditor)
{
}

String MainContentComponent::encrypt(const String & input)
{
	String upper = input.toUpperCase();
	String result = "";
	for (int i = 0; i < upper.length(); i++) {
		juce_wchar v = (juce_wchar)upper[i];

		if (v >= 'A' && v <= 'Z') {
			result += (juce_wchar)(((v - 'A') % 7) + 'A');
		}
		else if (v >= 9 && v <= 32) {
			result += v;
		}
	}
	return result;
}
