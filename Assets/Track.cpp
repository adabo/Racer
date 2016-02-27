#pragrma once

class Track
{
public:
    Track();
    void DrawTrack( int x,int y,D3DGraphics* gfx )
    {
        // Draw north outer
        // ==================================================
        for( int row = 0; row < 600; row++ )
        {
            gfx->DrawLine( x,y + row,x + 599,y + row, )
        }
        // Draw north inner
        for( int row = 0; row < 560; row++ )
        {
            gfx->DrawLine( x + 20,y + 20 + row,x + 580,y + 20 + row)
        }
        // Draw north inner inner
        for( int row = 0; row < 480; row++ )
        {
            gfx->DrawLine( x + 20,y + 20 + row,x + 580,y + 20 + row)
        }
        
        // Draw south outer
        // ==================================================
        for( int row = 0; row < 600; row++ )
        {
            gfx->DrawLine( x + 599,y + row,x + 599,y + row, )
        }
        // Draw south inner
        for( int row = 0; row < 560; row++ )
        {
            gfx->DrawLine( x + 599,y + row,x + 599,y + row, )
        }
        // Draw south inner
        for( int row = 0; row < 480; row++ )
        {
            gfx->DrawLine( x + 599,y + row,x + 599,y + row, )
        }
        
        // Draw east outer
        // ==================================================
        for( int col = 0; col < 20; col++ )
        {
            gfx->DrawLine( x + 580 + col,y + 80,x + 580 + col,y + 540, )
        }
        // Draw east inner
        for( int col = 0; col < 40; col++ )
        {
            gfx->DrawLine( x + 540 + col,y + 80,x + 540 + col,y + 540, )
        }
        // Draw east inner inner
        for( int col = 0; col < 40; col++ )
        {
            gfx->DrawLine( x + 520 + col,y + 80,x + 520 + col,y + 520, )
        }
        
        // Draw west outer
        // ==================================================
        for( int col = 0; col < 20; col++ )
        {
            gfx->DrawLine( x + col,y + 80,x + col,y + 540, )
        }
        // Draw west inner
        for( int col = 0; col < 40; col++ )
        {
            gfx->DrawLine( x + 20 + col,y + 80,x + 20 + col,y + 540, )
        }
        // Draw west inner inner
        for( int col = 0; col < 40; col++ )
        {
            gfx->DrawLine( x + 60 + col,y + 80,x + 60 + col,y + 520, )
        }
    }
}