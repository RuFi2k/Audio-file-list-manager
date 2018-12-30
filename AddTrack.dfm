object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Add track'
  ClientHeight = 290
  ClientWidth = 242
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 69
    Top = 11
    Width = 27
    Height = 24
    Caption = 'Name'
  end
  object Label2: TLabel
    Left = 8
    Top = 38
    Width = 88
    Height = 13
    Caption = 'Interner Resource'
  end
  object Label3: TLabel
    Left = 62
    Top = 65
    Width = 34
    Height = 21
    Caption = 'Format'
  end
  object Label4: TLabel
    Left = 55
    Top = 92
    Width = 41
    Height = 13
    Caption = 'Duration'
  end
  object Label5: TLabel
    Left = 66
    Top = 119
    Width = 30
    Height = 13
    Caption = 'Codec'
  end
  object Label6: TLabel
    Left = 33
    Top = 146
    Width = 63
    Height = 13
    Caption = 'Karaoke(0/1)'
  end
  object Label7: TLabel
    Left = 6
    Top = 178
    Width = 90
    Height = 13
    Caption = 'Discretization clock'
  end
  object Label8: TLabel
    Left = 62
    Top = 200
    Width = 32
    Height = 13
    Caption = 'Bitrate'
  end
  object Label9: TLabel
    Left = 39
    Top = 227
    Width = 57
    Height = 13
    Caption = 'PlayerName'
  end
  object NameEdit: TEdit
    Left = 112
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object ResEdit: TEdit
    Left = 112
    Top = 35
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object FormatEdit: TEdit
    Left = 112
    Top = 62
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object DurEdit: TEdit
    Left = 112
    Top = 89
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object CodecEdit: TEdit
    Left = 112
    Top = 116
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object ClockEdit: TEdit
    Left = 112
    Top = 170
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object TextEdit: TEdit
    Left = 112
    Top = 143
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object PlayerEdit: TEdit
    Left = 112
    Top = 224
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object BitrateEdit: TEdit
    Left = 112
    Top = 197
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object Button1: TButton
    Left = 8
    Top = 251
    Width = 226
    Height = 31
    Caption = 'Add Track'
    TabOrder = 9
    OnClick = Button1Click
  end
end
