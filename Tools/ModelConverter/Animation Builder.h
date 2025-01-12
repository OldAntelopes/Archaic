
#ifndef ANIMATION_BUILDER_H
#define ANIMATION_BUILDER_H

#ifdef __cplusplus
extern "C"
{
#endif


extern LRESULT CALLBACK AnimationBuilderDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


extern char*	maszAnimationUses[MAX_ANIMATION_USES];

extern void	AnimationBuilderAddNewKeyframe( int nHandle );

extern void	AnimationBuilderApplyNewKeyframes( void );


#ifdef __cplusplus
}
#endif



#endif