--- Arc/extensions/freetype/jni/freetype-2.10.4/include/freetype/config/ftmodule.h.orig	2023-11-26 13:46 UTC
+++ Arc/extensions/freetype/jni/freetype-2.10.4/include/freetype/config/ftmodule.h
@@ -12,19 +12,8 @@ FT_USE_MODULE( FT_Driver_ClassRec, tt_driver_class )
 
 FT_USE_MODULE( FT_Module_Class, autofit_module_class )
 FT_USE_MODULE( FT_Driver_ClassRec, tt_driver_class )
-FT_USE_MODULE( FT_Driver_ClassRec, t1_driver_class )
-FT_USE_MODULE( FT_Driver_ClassRec, cff_driver_class )
-FT_USE_MODULE( FT_Driver_ClassRec, t1cid_driver_class )
-FT_USE_MODULE( FT_Driver_ClassRec, pfr_driver_class )
-FT_USE_MODULE( FT_Driver_ClassRec, t42_driver_class )
-FT_USE_MODULE( FT_Driver_ClassRec, winfnt_driver_class )
-FT_USE_MODULE( FT_Driver_ClassRec, pcf_driver_class )
-FT_USE_MODULE( FT_Module_Class, psaux_module_class )
 FT_USE_MODULE( FT_Module_Class, psnames_module_class )
-FT_USE_MODULE( FT_Module_Class, pshinter_module_class )
-FT_USE_MODULE( FT_Renderer_Class, ft_raster1_renderer_class )
 FT_USE_MODULE( FT_Module_Class, sfnt_module_class )
 FT_USE_MODULE( FT_Renderer_Class, ft_smooth_renderer_class )
-FT_USE_MODULE( FT_Driver_ClassRec, bdf_driver_class )
 
 /* EOF */
