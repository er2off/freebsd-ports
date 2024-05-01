--- mcpelauncher-ui-qt/troubleshooter.cpp.orig	2024-05-01 08:23:14 UTC
+++ mcpelauncher-ui-qt/troubleshooter.cpp
@@ -10,7 +10,7 @@ QList<QObject*> Troubleshooter::findIssues() {
 QList<QObject*> Troubleshooter::findIssues() {
     QList<QObject*> ret;
     findLauncherIssues(ret);
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) // FreeBSD uses /usr/local/bin/zenity
     if (!QFileInfo("/usr/bin/zenity").exists()) {
         ret.append((new TroubleshooterIssue(TroubleshooterIssue::TYPE_LAUNCHER_ZENITY_NOT_FOUND, tr("Zenity utility not found"), tr("You may be unable to pick files in the launcher.")))
                            ->addWikiUrl("https://mcpelauncher.readthedocs.io/en/latest/troubleshooting.html#file-picking-doesn-t-work-or-crashes"));
@@ -57,4 +57,4 @@ void Troubleshooter::findLauncherIssues(QList<QObject 
     if (versionInfo["MSA daemon path"].isEmpty())
         ret.append((new TroubleshooterIssue(TroubleshooterIssue::TYPE_LAUNCHER_MSA_NOT_FOUND, tr("MSA daemon could not be found"), tr("The MSA component has not been installed properly. Xbox Live login may not work.")))
                            ->addWikiUrl("https://mcpelauncher.readthedocs.io/en/latest/troubleshooting.html#msa-daemon-could-not-be-found"));
-}
\ No newline at end of file
+}
