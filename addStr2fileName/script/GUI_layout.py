import PySimpleGUI as psg

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

fileRead_layout = [[psg.Text('File select :')], 
                  [psg.Input(size=(60,7)), psg.FolderBrowse(key='-file_path-')], 
                  [psg.Button('Read')]]

log_layout_fileRead = [[psg.Button("Clear File list")], 
                       [psg.Text('File List :')], 
                       [psg.Output(size=(60,7), key='-logFileRead-')]]

addStr_layout = [[psg.InputText(key='-str-', size=(60,7))],
                 [psg.Button('Add')]]

log_layout_addStr = [[psg.Button("Clear NEW File list")], 
                       [psg.Text('NEW File List :')], 
                       [psg.Output(size=(60,7), key='-logAddStr-')]]

layout = [[psg.Frame('make File list', fileRead_layout, size=(500,120))], 
          [psg.Frame('Log : make File List', log_layout_fileRead, size=(500,200))], 
          [psg.Frame('add String to file name', addStr_layout, size=(500,80))], 
          [psg.Frame('Log : add String to file name', log_layout_addStr, size=(500,200))],
          [psg.Button('Close')]]