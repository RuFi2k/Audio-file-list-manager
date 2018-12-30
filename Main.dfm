object Form17: TForm17
  Left = 416
  Top = 150
  Caption = 'Course work by RuFi (c) All rights reserved'
  ClientHeight = 369
  ClientWidth = 695
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object MusicList: TStringGrid
    Left = 0
    Top = 0
    Width = 609
    Height = 446
    ColCount = 9
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    ScrollBars = ssVertical
    TabOrder = 0
    OnSelectCell = MusicListSelectCell
    ColWidths = (
      64
      64
      64
      64
      64
      64
      64
      64
      64)
    RowHeights = (
      24)
  end
  object Button1: TButton
    Left = 615
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Add Track'
    TabOrder = 1
    OnClick = Button1Click
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 328
    object File1: TMenuItem
      Caption = '&File'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Save1: TMenuItem
        Caption = 'Save'
        OnClick = Save1Click
      end
    end
    object Find1: TMenuItem
      Caption = 'Find'
      object Codec1: TMenuItem
        Caption = 'Codec'
        OnClick = Codec1Click
      end
      object Bitrate1: TMenuItem
        Caption = 'Bitrate'
        OnClick = Bitrate1Click
      end
    end
    object ResourceTask1: TMenuItem
      Caption = 'Same resource'
      object ask1: TMenuItem
        Caption = 'Sorted by clock'
        OnClick = ask1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    FileName = 'C:\Users\RuFi\Desktop\CourseWork\Find.h'
    Filter = 'Text files|*.txt'
    Left = 80
    Top = 336
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Text files|*.txt'
    Left = 136
    Top = 336
  end
end
