import GUI_layout
import make_fileList as makeFL
import addSecurityClass as addSC
import PySimpleGUI as psg
import os
import sys

def resource_path(relative):
    if hasattr(sys, '_MEIPASS'):
        return os.path.join(sys._MEIPASS, relative)
    return os.path.join(os.path.abspath('.'), relative)
icon_path = resource_path("ai.ico")

psg.LOOK_AND_FEEL_TABLE['MyTheme'] = {
	'BACKGROUND': '#FFE5F0',
	'TEXT': 'black',
	'INPUT': '#E5FFFF',
	'SCROLL': '#E3E3E3',
	'TEXT_INPUT': 'black',
	'BUTTON': ('white', '#FF85B6'),
	'PROGRESS': psg.DEFAULT_PROGRESS_BAR_COLOR,
	'BORDER': 1,
	'SLIDER_DEPTH': 0,
	'PROGRESS_DEPTH': 0
}

psg.theme('MyTheme')

window = psg.Window('add Stirng', GUI_layout.layout, icon=icon_path)

while True:
    event, value = window.read() # イベント読み取り（ここでイベント待ち）
    if event == 'Read':
        fileList = makeFL.mk_fList(value['-file_path-'])
        window.find_element('-logFileRead-').Update(fileList)
    elif event == 'Add':
        newList = addSC.addSecCls(fileList, value['-file_path-'], value['-str-'])
        window.find_element('-logAddStr-').Update(newList)
    elif event == 'Clear File list':
        window.find_element('-logFileRead-').Update('')
    elif event == 'Clear NEW File list':
        window.find_element('-logAddStr-').Update('')
    elif event == 'Close':
        window.close()
    elif event == WIN_CLOSED:
        window.close()
