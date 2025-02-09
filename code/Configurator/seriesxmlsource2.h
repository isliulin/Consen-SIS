#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 不要修改此文件的内容。如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CSeriesxmlsource2 包装类

class CSeriesxmlsource2 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CSeriesxmlsource2)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x17D6DF37, 0xEC2A, 0x45CD, { 0x8F, 0xD6, 0x33, 0x6D, 0x98, 0x33, 0xF8, 0x2D } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:
enum
{
    bvNone = 0,
    bvLowered = 1,
    bvRaised = 2
}EPanelBevel;
enum
{
    bsNone = 0,
    bsSingle = 1
}EBorderStyle;
enum
{
    dmManual = 0,
    dmAutomatic = 1
}EDragMode;
enum
{
    psSolid = 0,
    psDash = 1,
    psDot = 2,
    psDashDot = 3,
    psDashDotDot = 4,
    psClear = 5,
    psInsideFrame = 6,
    psSmallDots = 7
}EChartPenStyle;
enum
{
    lsAuto = 0,
    lsSeries = 1,
    lsValues = 2,
    lsLastValues = 3,
    lsSeriesGroups = 4
}ELegendStyle;
enum
{
    mbLeft = 1,
    mbRight = 2,
    mbMiddle = 4
}EMouseButton;
enum
{
    dsDragEnter = 0,
    dsDragLeave = 1,
    dsDragMove = 2
}EDragState;
enum
{
    gdTopBottom = 0,
    gdBottomTop = 1,
    gdLeftRight = 2,
    gdRightLeft = 3,
    gdFromCenter = 4,
    gdFromTopLeft = 5,
    gdFromBottomLeft = 6,
    gdRadial = 7,
    gdDiagonalUp = 8,
    gdDiagonalDown = 9
}EGradientDirection;
enum
{
    talAuto = 0,
    talNone = 1,
    talValue = 2,
    talMark = 3,
    talText = 4
}EAxisLabelStyle;
enum
{
    aTopAxis = 0,
    aBottomAxis = 1,
    aBothHorizAxis = 2,
    aCustomHorizAxis = 3
}EHorizontalAxis;
enum
{
    bsSolid = 0,
    bsClear = 1,
    bsHorizontal = 2,
    bsVertical = 3,
    bsFDiagonal = 4,
    bsBDiagonal = 5,
    bsCross = 6,
    bsDiagCross = 7,
    bsFill80 = 8,
    bsFill60 = 9,
    bsFill40 = 10,
    bsFill20 = 11,
    bsFill10 = 12,
    bsZigZag = 13,
    bsVertSmall = 14,
    bsHorizSmall = 15,
    bsDiagSmall = 16,
    bsBackDiagSmall = 17,
    bsCrossSmall = 18,
    bsBackCrossSmall = 19
}EBrushStyle;
enum
{
    maNone = 0,
    maStacked = 1,
    maStacked100 = 2
}EMultiArea;
enum
{
    mbNone = 0,
    mbSide = 1,
    mbStacked = 2,
    mbStacked100 = 3,
    mbSideAll = 4,
    mbSelfStack = 5
}EMultiBar;
enum
{
    smsValue = 0,
    smsPercent = 1,
    smsLabel = 2,
    smsLabelPercent = 3,
    smsLabelValue = 4,
    smsLegend = 5,
    smsPercentTotal = 6,
    smsLabelPercentTotal = 7,
    smsXValue = 8,
    smsXY = 9,
    smsSeriesTitle = 10,
    smsPointIndex = 11,
    smsPercentRelative = 12
}EMarkStyle;
enum
{
    bsRectangle = 0,
    bsPyramid = 1,
    bsInvPyramid = 2,
    bsCilinder = 3,
    bsEllipse = 4,
    bsArrow = 5,
    bsRectGradient = 6,
    bsCone = 7,
    bsBevel = 8,
    bsSlantCube = 9,
    bsDiamond = 10,
    bsInvArrow = 11,
    bsInvCone = 12
}EBarStyle;
enum
{
    pmNone = 0,
    pmHorizontal = 1,
    pmVertical = 2,
    pmBoth = 3
}EChartScroll;
enum
{
    laLeft = 0,
    laRight = 1,
    laTop = 2,
    laBottom = 3
}ELegendAlignment;
enum
{
    ltsPlain = 0,
    ltsLeftValue = 1,
    ltsRightValue = 2,
    ltsLeftPercent = 3,
    ltsRightPercent = 4,
    ltsXValue = 5,
    ltsValue = 6,
    ltsPercent = 7,
    ltsXAndValue = 8,
    ltsXAndPercent = 9
}ELegendTextStyle;
enum
{
    atLeft = 0,
    atTop = 1,
    atRight = 2,
    atBottom = 3,
    atDepth = 4,
    atCustom = 5
}EAxisType;
enum
{
    dtOneMicrosecond = 0,
    dtOneMillisecond = 1,
    dtOneSecond = 2,
    dtFiveSeconds = 3,
    dtTenSeconds = 4,
    dtFifteenSeconds = 5,
    dtThirtySeconds = 6,
    dtOneMinute = 7,
    dtFiveMinutes = 8,
    dtTenMinutes = 9,
    dtFifteenMinutes = 10,
    dtThirtyMinutes = 11,
    dtOneHour = 12,
    dtTwoHours = 13,
    dtSixHours = 14,
    dtTwelveHours = 15,
    dtOneDay = 16,
    dtTwoDays = 17,
    dtThreeDays = 18,
    dtOneWeek = 19,
    dtHalfMonth = 20,
    dtOneMonth = 21,
    dtTwoMonths = 22,
    dtThreeMonths = 23,
    dtFourMonths = 24,
    dtSixMonths = 25,
    dtOneYear = 26,
    dtNone = 27
}EDateTimeStep;
enum
{
    jpegBestQuality = 0,
    jpegBestSpeed = 1
}EJPEGPerformance;
enum
{
    clTeeColor = 536870912,
    clNone = 536870911
}EConstants;
enum
{
    tfCopy = 0,
    tfAdd = 1,
    tfSubtract = 2,
    tfMultiply = 3,
    tfDivide = 4,
    tfAverage = 5,
    tfHigh = 6,
    tfLow = 7,
    tfMovavg = 8,
    tfExpavg = 9,
    tfMomentum = 10,
    tfCurveFit = 11,
    tfRSI = 12,
    tfTrend = 13,
    tfStdDeviation = 14,
    tfCumulative = 15,
    tfCount = 16,
    tfExpTrend = 17,
    tfExpMovAvg = 18,
    tfMomentumDiv = 19,
    tfRMS = 20,
    tfMACD = 21,
    tfStochastic = 22,
    tfBollinger = 23,
    tfADX = 24,
    tfSmoothing = 25,
    tfCustom = 26,
    tfCompress = 27,
    tfCrossPoints = 28,
    tfCLV = 29,
    tfOBV = 30,
    tfCCI = 31,
    tfPVO = 32,
    tfPerformance = 33,
    tfMode = 34,
    tfMedian = 35,
    tfCorrelation = 36,
    tfVariance = 37,
    tfPerimeter = 38,
    tfDownSampleFun = 39,
    tfSubset = 40,
    tfHistogram = 41,
    tfSAR = 42
}EFunctionType;
enum
{
    xysPixels = 0,
    xysAxis = 1,
    xysAxisOrigin = 2
}EShapeXYStyle;
enum
{
    csCandleStick = 0,
    csCandleBar = 1,
    csOpenClose = 2,
    csLine = 3
}ECandleStyle;
enum
{
    ewuPercent = 0,
    ewuPixels = 1
}EErrorWidthUnits;
enum
{
    loNone = 0,
    loAscending = 1,
    loDescending = 2
}EValueListOrder;
enum
{
    chasRectangle = 0,
    chasCircle = 1,
    chasVertLine = 2,
    chasHorizLine = 3,
    chasTriangle = 4,
    chasInvertTriangle = 5,
    chasLine = 6,
    chasDiamond = 7,
    chasCube = 8,
    chasCross = 9,
    chasDiagCross = 10,
    chasStar = 11,
    chasPyramid = 12,
    chasInvertPyramid = 13
}EShapeStyle;
enum
{
    scLine = 0,
    scBar = 1,
    scHorizBar = 2,
    scArea = 3,
    scPoint = 4,
    scPie = 5,
    scFastLine = 6,
    scShape = 7,
    scGantt = 8,
    scBubble = 9,
    scArrow = 10,
    scCandle = 11,
    scPolar = 12,
    scSurface = 13,
    scVolume = 14,
    scErrorBar = 15,
    scBezier = 16,
    scContour = 17,
    scError = 18,
    scPoint3D = 19,
    scRadar = 20,
    scClock = 21,
    scWindRose = 22,
    scBar3D = 23,
    scImageBar = 24,
    scDonut = 25,
    scTriSurface = 26,
    scBox = 27,
    scHorizBox = 28,
    scHistogram = 29,
    scColorGrid = 30,
    scBarJoin = 31,
    scHighLow = 32,
    scWaterfall = 33,
    scSmith = 34,
    scPyramid = 35,
    scMap = 36,
    scHorizLine = 37,
    scFunnel = 38,
    scCalendar = 39,
    scHorizArea = 40,
    scPointFigure = 41,
    scGauge = 42,
    scVector3D = 43,
    scTower = 44,
    scPolarBar = 45,
    scBubble3D = 46,
    scHorizHistogram = 47,
    scVolumePipe = 48,
    scIsoSurface = 49,
    scDarvas = 50,
    scHighLowLine = 51,
    scPolarGrid = 52,
    scDeltaPoint = 53,
    scImagePoint = 54,
    scOrganizational = 55,
    scWorld = 56,
    scTagCloud = 57,
    scKagi = 58,
    scRenko = 59,
    scNumericGauge = 60,
    scLinearGauge = 61,
    scCircularGauge = 62,
    scBigCandle = 63,
    scLinePoint = 64
}ESeriesClass;
enum
{
    poPortrait = 0,
    poLandscape = 1
}EPrinterOrientation;
enum
{
    psRectangle = 0,
    psCircle = 1,
    psTriangle = 2,
    psDownTriangle = 3,
    psCross = 4,
    psDiagCross = 5,
    psStar = 6,
    psDiamond = 7,
    psSmallDot = 8,
    psNothing = 9,
    psLeftTriangle = 10,
    psRightTriangle = 11,
    psHexagon = 12
}EPointerStyle;
enum
{
    cfPolynomial = 0,
    cfLogarithmic = 1,
    cfExponential = 2
}ETypeFitting;
enum
{
    pbmStretch = 0,
    pbmTile = 1,
    pbmCenter = 2,
    pbmCustom = 3
}EBackImageMode;
enum
{
    aLeft = 0,
    aRight = 1,
    aCenter = 2
}ETextAlignment;
enum
{
    aLeftAxis = 0,
    aRightAxis = 1,
    aBothVertAxis = 2,
    aCustomVertAxis = 3
}EVerticalAxis;
enum
{
    ssShift = 1,
    ssAlt = 2,
    ssCtrl = 4,
    ssNone = 0
}EShiftState;
enum
{
    taLeftJustify = 0,
    taRightJustify = 1,
    taCenter = 2
}ETitleAlignment;
enum
{
    cbmOpaque = 2,
    cbmTransparent = 1,
    cbmNone = 0
}ECanvasBackMode;
enum
{
    ctaLeft = 0,
    ctaCenter = 1,
    ctaRight = 2
}ECanvasTextAlign;
enum
{
    poNone = 0,
    poBelowPercent = 1,
    poBelowValue = 2
}EPieOtherStyle;
enum
{
    essLeft = 0,
    essRight = 1,
    essLeftRight = 2,
    essTop = 3,
    essBottom = 4,
    essTopBottom = 5
}EErrorSeriesStyle;
enum
{
    paFirst = 0,
    paCenter = 1,
    paLast = 2
}EFunctionPeriodAlign;
enum
{
    psNumPoints = 0,
    psRange = 1
}EFunctionPeriodStyle;
enum
{
    epMain = 0,
    epGeneral = 1,
    epAxis = 2,
    epTitles = 3,
    epLegend = 4,
    epPanel = 5,
    epPaging = 6,
    epWalls = 7,
    epAspect = 8,
    epSeriesGeneral = 9,
    epSeriesMarks = 10,
    epAllSeries = 11,
    epSeriesData = 12,
    epExport = 13,
    epTools = 14,
    epPrintPreview = 15,
    epOpenGL = 16
}ETeeEditorPage;
enum
{
    stJpeg = 0,
    stTeeTemplate = 1
}EStreamType;
enum
{
    cssHorizontal = 0,
    cssVertical = 1,
    cssBoth = 2,
    cssScope = 3
}ECursorToolStyle;
enum
{
    aaStart = 0,
    aaEnd = 1,
    aaBoth = 2
}EAxisArrowToolPosition;
enum
{
    hsNone = 0,
    hsCircle = 1,
    hsRectangle = 2,
    hsDiamond = 3,
    hsSeries = 4
}ENearestToolStyle;
enum
{
    fosRectangle = 0,
    fosRoundRectangle = 1
}EChartObjectShapeStyle;
enum
{
    tcCursor = 0,
    tcDragMarks = 1,
    tcAxisArrow = 2,
    tcDrawLine = 3,
    tcNearest = 4,
    tcColorband = 5,
    tcColorLine = 6,
    tcRotate = 7,
    tcMarksTip = 8,
    tcChartImage = 9,
    tcAnnotate = 10,
    tcPageNumber = 11,
    tcGridTranspose = 12,
    tcExtraLegend = 13,
    tcSeriesAnimation = 14,
    tcGantt = 15,
    tcGridBand = 16,
    tcPie = 17,
    tcDragPoint = 18,
    tcLegendScrollBar = 19,
    tcLight = 20,
    tcSurfaceNearest = 21,
    tcAxisScroll = 22,
    tcSeriesBand = 23,
    tcSelector = 24,
    tcRectangle = 25,
    tcDataTable = 26,
    tcClipSeries = 27,
    tcSeriesStats = 28,
    tcVideo = 29,
    tcVideoPlayer = 30,
    tcTransposeSeries = 31,
    tcSeriesRegion = 32,
    tcAntiAlias = 33,
    tcFader = 34,
    tcFrame = 35,
    tcMagnify = 36,
    tcLegendPalette = 37,
    tcBanner = 38,
    tcText3D = 39,
    tcSubChart = 40,
    tcLink = 41,
    tcFibonacci = 42,
    tcFullScreen = 43
}EToolClass;
enum
{
    spLeft = 0,
    spRight = 1
}ELegendSymbolPosition;
enum
{
    lcsPercent = 0,
    lcsPixels = 1
}ELegendSymbolSize;
enum
{
    tzdHorizontal = 0,
    tzdVertical = 1,
    tzdBoth = 2
}ETeeZoomDirection;
enum
{
    ppoDefault = 0,
    ppoPortrait = 1,
    ppoLandscape = 2
}ETeePreviewPanelOrientation;
enum
{
    rsiOpenClose = 0,
    rsiClose = 1
}ERSIStyle;
enum
{
    cssNone = 0,
    cssOverlap = 1,
    cssStack = 2,
    cssStack100 = 3
}ECustomSeriesStack;
enum
{
    vaTop = 0,
    vaCenter = 1,
    vaBottom = 2
}ETeeVertAlign;
enum
{
    alDefault = 0,
    alOpposite = 1
}EAxisLabelAlign;
enum
{
    bsWindows = 0,
    bsBezier3 = 1,
    bsBezier4 = 2
}EBezierStyle;
enum
{
    psPale = 0,
    psStrong = 1,
    psGrayScale = 2,
    psInvGray = 3,
    psRainbow = 4,
    psCustom = 5
}EPaletteStyle;
enum
{
    gcLZW = 0,
    gcRLE = 1
}EGIFCompression;
enum
{
    dmNearest = 0,
    dmFloydSteinberg = 1,
    dmStucki = 2,
    dmSierra = 3,
    dmJaJuNI = 4,
    dmSteveArche = 5,
    dmBurkes = 6
}EGIFDitherMode;
enum
{
    rmNone = 0,
    rmWindows20 = 1,
    rmWindows256 = 2,
    rmWindowsGray = 3,
    rmMonochrome = 4,
    rmGrayScale = 5,
    rmNetscape = 6,
    rmQuantize = 7,
    rmQuantize256 = 8
}EGIFColorReduction;
enum
{
    pfDevice = 0,
    pf1bit = 1,
    pf4bit = 2,
    pf8bit = 3,
    pf15bit = 4,
    pf16bit = 5,
    pf24bit = 6,
    pf32bit = 7
}EPixelFormat;
enum
{
    mtmMove = 0,
    mtmClick = 1
}EMarkToolMouseAction;
enum
{
    tcbNormal = 0,
    tcbSeparator = 1,
    tcbRotate = 2,
    tcbMove = 3,
    tcbZoom = 4,
    tcbDepth = 5,
    tcbEdit = 6,
    tcbPrintPreview = 7,
    tcbCopy = 8,
    tcbSave = 9,
    tcbLabel = 10,
    tcb3D = 11
}ETeeCommanderControls;
enum
{
    ppLeftTop = 0,
    ppLeftBottom = 1,
    ppRightTop = 2,
    ppRightBottom = 3,
    ppCenter = 4
}EAnnotationPosition;
enum
{
    dstAllRecords = 0,
    dstSingleRecord = 1
}EDatasourceType;
enum
{
    esRound = 0,
    esSquare = 1,
    esFlat = 2
}EPenEndStyle;
enum
{
    muPercent = 0,
    muPixels = 1
}EMarginUnits;
enum
{
    clCustom = 0,
    clMaximum = 1,
    clCenter = 2,
    clMinimum = 3
}EColorLineStyle;
enum
{
    ahNone = 0,
    ahLine = 1,
    ahSolid = 2
}EArrowHeadStyle;
enum
{
    pbStart = 0,
    pbAll = 1,
    pbEnd = 2
}EGanttToolPartBar;
enum
{
    ptFocus = 0,
    ptExplode = 1
}EPieToolStyle;
enum
{
    ocDay = 0,
    ocWeek = 1,
    ocMonth = 2,
    ocBiMonth = 3,
    ocQuarter = 4,
    ocYear = 5
}ECompressionPeriod;
enum
{
    hsLine = 0,
    hsTriangle = 1
}EHandStyle;
enum
{
    tsCube = 0,
    tsRectangle = 1,
    tsCover = 2,
    tsCylinder = 3,
    tsArrow = 4,
    tsCone = 5,
    tsPyramid = 6,
    tsSlantCube = 7
}ETowerStyle;
enum
{
    gfCount = 0,
    gfSum = 1
}EGroupFormula;
enum
{
    dsX = 0,
    dsY = 1,
    dsBoth = 2
}EDragPointStyle;
enum
{
    puPercent = 0,
    puPixels = 1
}EPositionUnits;
enum
{
    dsAlways = 0,
    dsWhenNeeded = 1
}EScrollBarDrawStyle;
enum
{
    lsLinear = 0,
    lsSpotLight = 1
}ELightStyle;
enum
{
    ctDefault = 0,
    ctExcel = 1,
    ctClassic = 2,
    ctBusiness = 3,
    ctWeb = 4,
    ctWindowsXP = 5,
    ctBlueSky = 6,
    ctFacts = 7,
    ctRandom = 8,
    ctOpera = 9
}EChartTheme;
enum
{
    cpTeeChart = 0,
    cpExcel = 1,
    cpVictorian = 2,
    cpPastel = 3,
    cpSolid = 4,
    cpClassic = 5,
    cpWeb = 6,
    cpModern = 7,
    cpRainbow = 8,
    cpWindowsXP = 9,
    cpMacOS = 10,
    cpWinVista = 11,
    cpGrayScale = 12,
    cpOpera = 13,
    cpWarm = 14,
    cpCool = 15
}EColorPalette;
enum
{
    dsDouglas = 0,
    dsMax = 1,
    dsMin = 2,
    dsMinMax = 3,
    dsAverage = 4
}EDownSampleMethod;
enum
{
    gaYes = 0,
    gaNo = 1,
    gaSome = 2
}ESeriesGroupActive;
enum
{
    cbsCheck = 0,
    cbsRadio = 1
}ECheckBoxesStyle;
enum
{
    cssRelativeToOpen = 0,
    cssRelativeToClose = 1
}ECandleColorStyle;
enum
{
    lmClear = 0,
    lmAppend = 1
}ELoadMode;
enum
{
    fcConvolve = 0,
    fcBlur = 1,
    fcResize = 2,
    fcCrop = 3,
    fcInvert = 4,
    fcGrayScale = 5,
    fcFlip = 6,
    fcReverse = 7,
    fcAmount = 8,
    fcMosaic = 9,
    fcBrightness = 10,
    fcContrast = 11,
    fcColor = 12,
    fcHueLumSat = 13,
    fcSharpen = 14,
    fcEmboss = 15,
    fcSoften = 16,
    fcGammaCorrection = 17,
    fcRotate = 18,
    fcMirror = 19,
    fcTile = 20,
    fcBevel = 21,
    fcZoom = 22
}EFilterClass;
enum
{
    gmSimple = 0,
    gmEye = 1,
    gmEye2 = 2
}EGrayMethod;
enum
{
    mdDown = 0,
    mdUp = 1,
    mdRight = 2,
    mdLeft = 3
}EMirrorDirection;
enum
{
    lmLine = 0,
    lmCylinder = 1,
    lmRectangle = 2
}EPenLineMode;
enum
{
    scsRectangle = 0,
    scsCircle = 1,
    scsDiamond = 2,
    scsEmpty = 3,
    scsCamera = 4
}EScopeCursorStyle;
enum
{
    ssDefault = 0,
    ssHorizontal = 1,
    ssVertical = 2
}ESnapStyle;
enum
{
    dlLine = 0,
    dlHorizParallel = 1,
    dlVertParallel = 2,
    dlRectangle = 3,
    dlEllipse = 4
}EDrawLineStyle;
enum
{
    pmBlack = 0,
    pmWhite = 1,
    pmNop = 2,
    pmNot = 3,
    pmCopy = 4,
    pmNotCopy = 5,
    pmMergePenNot = 6,
    pmMaskPenNot = 7,
    pmMergeNotPen = 8,
    pmMaskNotPen = 9,
    pmMerge = 10,
    pmNotMerge = 11,
    pmMask = 12,
    pmNotMask = 13,
    pmXor = 14,
    pmNotXor = 15
}EPenMode;
enum
{
    fsFadeIn = 0,
    fsFadeOut = 1
}EFaderStyle;
enum
{
    laDefault = 0,
    laOther = 1,
    laBoth = 2
}ELegendPaletteAxis;
enum
{
    sdRightLeft = 0,
    sdLeftRight = 1
}EScrollDirection;
enum
{
    cpX = 0,
    cpY = 1,
    cpZ = 2
}ECanvas3DPlane;
enum
{
    rsAll = 0,
    rsRotation = 1,
    rsElevation = 2
}ERotateToolStyle;
enum
{
    stsCustom = 0,
    stsThumb1 = 1,
    stsThumb2 = 2,
    stsThumb3 = 3
}EScrollThumbStyle;
enum
{
    cgsAuto = 0,
    cgsNo = 1,
    cgsYes = 2
}EChartGridShow;
enum
{
    salNo = 0,
    salOneWay = 1,
    salCircular = 2
}ESeriesAnimationLoop;
enum
{
    disSmiles = 0,
    disHands = 1
}EDeltaImageStyle;
enum
{
    lsSquared = 0,
    lsDiagonal = 1
}EOrgLineStyle;
enum
{
    wmWorld = 0,
    wmAfrica = 1,
    wmAsia = 2,
    wmAustralia = 3,
    wmCentralAmerica = 4,
    wmEurope = 5,
    wmEurope15 = 6,
    wmEurope27 = 7,
    wmSpain = 8,
    wmMiddleEast = 9,
    wmNorthAmerica = 10,
    wmSouthAmerica = 11,
    wmUSA = 12,
    wmUSAHawaiiAlaska = 13
}EWorldMap;
enum
{
    toText = 0,
    toValue = 1,
    toNone = 2
}ETagCloudOrder;
enum
{
    tnDontPaint = 0,
    tnSkip = 1,
    tnIgnore = 2
}ETreatNullsStyle;
enum
{
    mpAutomatic = 0,
    mpDisabled = 1
}EMultiPie;
enum
{
    dfBar = 0,
    dfDot = 1,
    dfCustom = 2
}EDigitalFont;
enum
{
    gpHand = 0,
    gpCenter = 1,
    gpTick = 2,
    gpMinorTick = 3,
    gpColorLine = 4
}EGaugePointerStyles;
enum
{
    fsArc = 0,
    fsFan = 1
}EFibonacciStyle;
enum
{
    maPercentFont = 0,
    maPercentSize = 1,
    maPixels = 2
}EMarginsUnits;


// 操作
public:

// ISeriesXMLSource

// Functions
//

	void put_Chart(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x2c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void put_ChartLink(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Open()
	{
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Close()
	{
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_Active()
	{
		BOOL result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Active(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x12f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_Series()
	{
		VARIANT result;
		InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Series(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x130, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	void Load()
	{
		InvokeHelper(0x191, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void LoadFromFile(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x192, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	void LoadFromURL(LPCTSTR URL)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x193, DISPATCH_METHOD, VT_EMPTY, NULL, parms, URL);
	}
	CString get_FileName()
	{
		CString result;
		InvokeHelper(0x194, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_FileName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x194, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_LoadMode()
	{
		long result;
		InvokeHelper(0x195, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_LoadMode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x195, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_SeriesNode()
	{
		CString result;
		InvokeHelper(0xd2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_SeriesNode(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ValueSource()
	{
		CString result;
		InvokeHelper(0xd3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_ValueSource(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_XML()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

// Properties
//



};
