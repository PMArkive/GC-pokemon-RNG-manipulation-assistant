#pragma once

#include <QCheckBox>
#include <QComboBox>
#include <QFuture>
#include <QMainWindow>
#include <QMenu>
#include <QProgressDialog>
#include <QPushButton>

#include "../Common/CommonTypes.h"
#include "Predictor/PredictorWidget.h"
#include "StatsReporter/StatsReporterWidget.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

  void gameChanged();
  void startSeedFinder();
  void resetPredictor();
  // Returns whether we have a desired prediction after the reroll
  bool rerollPredictor();
  void autoRerollPredictor();
  void openSettings();
  void generatePrecalc();
  void precalcDone();

signals:
  void onUpdatePrecalcProgress(const long value);
  void onPrecalcDone();

private:
  void initialiseWidgets();
  void makeLayouts();
  void makeMenus();

  QMenu* m_menuFile;
  QMenu* m_menuEdit;
  QMenu* m_menuHelp;

  QAction* m_actGenerationPrecalcFile;
  QComboBox* m_cmbGame;
  QPushButton* m_btnStartSeedFinder;
  QPushButton* m_btnSettings;
  QPushButton* m_btnReset;
  QPushButton* m_btnRerollPrediciton;
  QPushButton* m_btnAutoRerollPrediciton;

  QLabel* m_lblRerollCount;
  QCheckBox* m_chkFilterUnwantedPredictions;
  PredictorWidget* m_predictorWidget;
  StatsReporterWidget* m_statsReporterWidget;
  bool m_cancelPrecalc = false;
  QFuture<void> m_precalcFuture;
  QProgressDialog* m_dlgProgressPrecalc;
  u32 m_currentSeed = 0;
  int m_rerollCount = 0;
};
